/* $Header: /ker/io.386/RCS/mm.c,v 2.3 93/08/19 04:02:55 nigel Exp Locker: nigel $ */
/*
 * Memory Mapped Video
 * High level output routines.
 *
 * $Log:	mm.c,v $
 * Revision 2.3  93/08/19  04:02:55  nigel
 * Nigel's R83
 * 
 * Revision 2.2  93/07/26  15:32:02  nigel
 * Nigel's R80
 * 
 * Revision 1.4  92/04/09  10:25:38  hal
 * Call mmgo() from mmstart() at low priority.
 */

#include <kernel/timeout.h>

#include <sys/coherent.h>
#include <sys/sched.h>
#include <sys/errno.h>
#include <sys/stat.h>
#include <sys/io.h>
#include <sys/tty.h>


/* For beeper */
#define	TIMCTL	0x43			/* Timer control port */
#define	TIMCNT	0x42			/* Counter timer port */
#define	PORTB	0x61			/* Port containing speaker enable */
#define	FREQ	((int)(1193181L/440))	/* Counter for 440 Hz. tone */
extern int con_beep;			/* 1=beep 0=silent */

int mmtime();
extern char mmesc;	/* last unserviced escape character */

char mmbeeps;		/* number of ticks remaining on bell */
int  mmcrtsav = 1;	/* crt saver enabled */
int  mmvcnt   = 900;	/* seconds remaining before crt saver is activated */

extern TTY istty;

/*
 * Start the output stream.
 * Called from `ttwrite' and `isrint' routines.
 */
TIM mmtim;

mmstart(tp)
TTY * tp;
{
	static int mmbegun;

	if (mmbegun == 0) {
		++ mmbegun;
		timeout (& mmtim, HZ / 10, mmtime, (char *) tp);
	}

	while ((tp->t_flags & T_STOP) == 0) {
		IO		iob;
		char		c;
		int		temp;
		unsigned short	s;

		if ((temp = ttout (tp)) < 0)
			break;
		iob.io_seg = IOSYS;
		iob.io_ioc = 1;
		c = temp;
		iob.io.vbase = & c;
		iob.io_flag = 0;
#if 0
		mmwrite (makedev (2, 0), & iob);
#else
		s = splo ();
		mmgo (& iob);
		spl (s);
#endif
	}
}

mmtime(xp)
char *xp;
{
	int s;

	s = sphi();

	if (con_beep) {
		if (mmbeeps < 0) {
			mmbeeps = 2;

			/* Timer 2, lsb, msb, binary */
			outb (TIMCTL, 0xB6);
			outb (TIMCNT, FREQ & 0xFF);
			outb (TIMCNT, FREQ >> 8);

			/* Turn speaker on */
			outb (PORTB, inb (PORTB) | 3);
		} else if (mmbeeps > 0 && -- mmbeeps == 0)
			outb (PORTB, inb (PORTB) & ~ 3);
	}

	if (mmesc) {
		ismmfunc (mmesc);
		mmesc = 0;
	}
	spl (s);

	ttstart ((TTY *) xp);

	timeout (& mmtim, HZ / 10, mmtime, xp);
}

/**
 *
 * void
 * mmwatch()	-- turn video display off after 15 minutes inactivity.
 */
void
mmwatch()
{
	if (mmcrtsav > 0 && mmvcnt > 0 && -- mmvcnt == 0)
		mm_voff ();
}

mmwrite (dev, iop)
dev_t dev;
IO *iop;
{
	int ioc;
	int s;

	/*
	 * Kernel writes.
	 */
	if (iop->io_seg == IOSYS) {
		while (mmgo (iop))
			/* DO NOTHING */ ;
		return;
	}

#if 0
	ioc = iop->io_ioc;
	/*
	 * Blocking user writes.
	 */
	if ((iop->io_flag & IONDLY) == 0) {
		do {
			while (istty.t_flags & T_STOP) {
				s = sphi ();
				istty.t_flags |= T_HILIM;
				sleep ((char*) & istty.t_oq,
					CVTTOUT, IVTTOUT, SVTTOUT);
				spl (s);
			}

			/*
			 * Signal received.
			 */

			if (curr_signal_pending ()) {
				kbunscroll();	/* update kbd LEDS */

				/*
				 * No data transferred yet.
				 */

				if (ioc == iop->io_ioc)
					set_user_error (EINTR);
				else {
					/*
					 * Transfer remaining data
					 * without pausing after scrolling.
					 */
					while (mmgo (iop))
						/* DO NOTHING */ ;
				}
				return;
			}

			mmgo (iop);
		} while (iop->io_ioc != 0);
		return;
	}

	/*
	 * Non-blocking user writes with output stopped.
	 */
	if ((istty.t_flags & T_STOP) != 0) {
		set_user_error (EAGAIN);
		return;
	}

	/*
	 * Non-blocking user writes do not pause after scrolling.
	 */

	while (mmgo (iop))
		/* DO NOTHING */ ;
#else
	ttwrite (& istty, iop);
#endif
}
