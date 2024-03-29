/* (-lgl
 *	Coherent 386 release 4.2
 *	Copyright (c) 1982, 1993 by Mark Williams Company.
 *	All rights reserved. May not be copied without permission.
 *	For copying permission and licensing info, write licensing@mwc.com
 -lgl) */

#ifndef	__SYS_CONFINFO_H__
#define	__SYS_CONFINFO_H__

/*
 * This file contains definitions used by the automatically-generated
 * configuration file "conf.c". The generated code makes heavy use of macros
 * to allow the final result to be precisely tailored to the target system
 * without modification to the code generator.
 */

#include <common/ccompat.h>
#include <common/xdebug.h>
#include <common/__cred.h>
#include <common/_intmask.h>
#include <common/_uid.h>
#include <common/_off.h>
#include <sys/inline.h>
#include <sys/stream.h>
#include <sys/uio.h>


#ifdef	__USE_PROTO__
#define	DEF(ansi,k_r)		ansi
#else
#define	DEF(ansi,k_r)		k_r
#endif

/*
 * Since we don't import the definition of "buf", create an incomplete
 * definition at file scope. Same for "pollhead".
 */

struct buf;
struct pollhead;

#define	__OPEN(name)	__CONCAT (name, open)
#define	__CLOSE(name)	__CONCAT (name, close)
#define	__READ(name)	__CONCAT (name, read)
#define	__WRITE(name)	__CONCAT (name, write)
#define	__IOCTL(name)	__CONCAT (name, ioctl)
#define	__STRATEGY(name) __CONCAT (name, strategy)
#define	__PRINT(name)	__CONCAT (name, print)
#define	__SIZE(name)	__CONCAT (name, size)
#define	__CHPOLL(name)	__CONCAT (name, chpoll)
#define	__MMAP(name)	__CONCAT (name, mmap)
#define	__INTR(name)	__CONCAT (name, intr)
#define	__INIT(name)	__CONCAT (name, init)
#define	__HALT(name)	__CONCAT (name, halt)
#define	__START(name)	__CONCAT (name, start)
#define	__EXIT(name)	__CONCAT (name, exit)

#define	__INFO(name)	__CONCAT (name, info)
#define	__DEVFLAG(name)	__CONCAT (name, devflag)


typedef	int  (*	ddi_open_t)	__PROTO ((n_dev_t * _devp, int _oflag,
					  int _otyp, __cred_t * _credp));
#define	EXTERN_OPEN(name) __EXTERN_C__ \
  int	__OPEN (name)	__PROTO ((n_dev_t * _devp, int _oflag,\
					 int _otyp, __cred_t * _credp))

typedef	int  (* ddi_close_t)	__PROTO ((n_dev_t _dev, int _oflag, int _otyp,
					  __cred_t * _credp));
#define	EXTERN_CLOSE(name) __EXTERN_C__ \
  int	__CLOSE (name)	__PROTO ((n_dev_t _dev, int _oflag, int _otyp,\
					  __cred_t * _credp))

typedef	int  (*	ddi_read_t)	__PROTO ((n_dev_t _dev, uio_t * _uiop,
					  __cred_t * _credp));
#define	EXTERN_READ(name) __EXTERN_C__ \
  int	__READ (name)	__PROTO ((n_dev_t _dev, uio_t * _uiop,\
					  __cred_t * _credp))

typedef int  (*	ddi_write_t)	__PROTO ((n_dev_t _dev, uio_t * _uiop,
					  __cred_t * _credp));
#define	EXTERN_WRITE(name) __EXTERN_C__ \
  int	__WRITE (name)	__PROTO ((n_dev_t _dev, uio_t * _uiop,\
					  __cred_t * _credp))

typedef	int  (*	ddi_ioctl_t)	__PROTO ((n_dev_t _dev, int _cmd,
					  __VOID__ * _arg, int _mode,
					  __cred_t * _credp, int * _rvalp));
#define	EXTERN_IOCTL(name) __EXTERN_C__ \
  int	__IOCTL (name)	__PROTO ((n_dev_t _dev, int _cmd, __VOID__ * _arg,\
					  int _mode, __cred_t * _credp,\
					  int * _rvalp))

typedef	int  (*	ddi_strategy_t)	__PROTO ((struct buf * _bufp));
#define	EXTERN_STRATEGY(name) __EXTERN_C__ \
  int	__STRATEGY (name) __PROTO ((struct buf * _bufp))

typedef int  (*	ddi_print_t)	__PROTO ((n_dev_t _dev, char * _str));
#define	EXTERN_PRINT(name) __EXTERN_C__ \
  int	__PRINT (name)	__PROTO ((n_dev_t _dev, char * _str))

typedef int  (*	ddi_size_t)	__PROTO ((n_dev_t _dev));
#define	EXTERN_SIZE(name) __EXTERN_C__ \
  int	__SIZE (name)	__PROTO ((n_dev_t _dev))

typedef	int  (*	ddi_chpoll_t)	__PROTO ((n_dev_t _dev, short _events,
					  int _anyyet, short * _reventsp,
					  struct pollhead ** _phpp));
#define	EXTERN_CHPOLL(name) __EXTERN_C__ \
  int	__CHPOLL (name)	__PROTO ((n_dev_t _dev, short _events,\
					  int _anyyet, short * _reventsp,\
					  struct pollhead ** _phpp))

typedef	int  (*	ddi_mmap_t)	__PROTO ((n_dev_t _dev, off_t _off,
					  int _prot));
#define	EXTERN_MMAP(name) __EXTERN_C__ \
  int	__MMAP (name)	__PROTO ((n_dev_t _dev, off_t _off,\
					  int _prot))

typedef	int  (*	ddi_intr_t)	__PROTO ((int _ivec));
#define	EXTERN_INTR(name) __EXTERN_C__ \
  int	__INTR (name)	__PROTO ((int _ivec))

typedef void (*	ddi_init_t)	__PROTO ((void));
#define	EXTERN_INIT(name) __EXTERN_C__ \
  void	__INIT (name)	__PROTO ((void))

typedef	void (*	ddi_start_t)	__PROTO ((void));
#define	EXTERN_START(name) __EXTERN_C__ \
  void	__START (name)	__PROTO ((void))

typedef	void (*	ddi_exit_t)	__PROTO ((void));
#define	EXTERN_EXIT(name) __EXTERN_C__ \
  void	__EXIT (name)	__PROTO ((void))

typedef	void (*	ddi_halt_t)	__PROTO ((void));
#define	EXTERN_HALT(name) __EXTERN_C__ \
  void	__HALT (name)	__PROTO ((void))

#define	NULL_OPEN		((ddi_open_t) 0)
#define	NULL_CLOSE		((ddi_close_t) 0)
#define	NULL_READ		((ddi_read_t) 0)
#define	NULL_WRITE		((ddi_write_t) 0)
#define	NULL_IOCTL		((ddi_ioctl_t) 0)
#define	NULL_STRATEGY		((ddi_strategy_t) 0)
#define	NULL_PRINT		((ddi_print_t) 0)
#define	NULL_SIZE		((ddi_size_t) 0)
#define	NULL_CHPOLL		((ddi_chpoll_t) 0)
#define	NULL_MMAP		((ddi_mmap_t) 0)
#define	NULL_INTR		((ddi_intr_t) 0)
#define	NULL_INIT		((ddi_init_t) 0)
#define	NULL_START		((ddi_start_t) 0)
#define	NULL_EXIT		((ddi_exit_t) 0)
#define	NULL_HALT		((ddi_halt_t) 0)
#define	NULL_CON		((CON *) 0)

#if	__COHERENT__ || defined (__MSDOS__)

#if	! _KERNEL
#define	_KERNEL	2
#endif

#if	defined (__MSDOS__)
#include <sys/_con.h>
#else
#include <kernel/_buf.h>
#include <sys/con.h>
#endif

#include <sys/io.h>

#if	_KERNEL == 2
#undef	_KERNEL
#endif


__EXTERN_C_BEGIN__

void		_forward_open	__PROTO ((o_dev_t _dev, int _mode, int _flags,
					  __cred_t * _credp,
					  struct inode ** _inodepp,
					  ddi_open_t _funcp,
					  ddi_close_t _closep));
void		_forward_close	__PROTO ((o_dev_t _dev, int _mode, int _flags,
					  __cred_t * _credp, ddi_close_t _funcp));
void		_forward_read	__PROTO ((o_dev_t _dev, IO * _iop,
					  __cred_t * _credp, ddi_read_t _funcp));
void		_forward_write	__PROTO ((o_dev_t _dev, IO * _iop,
					  __cred_t * _credp, ddi_write_t _funcp));
void		_forward_ioctl	__PROTO ((o_dev_t _dev, int _cmd,
					  __VOID__ * _arg, int mode,
					  __cred_t * _credp, int * _rvalp,
					  ddi_ioctl_t _funcp));
#ifndef	__MSDOS__
void		_forward_strategy __PROTO ((__buf_t * _buf,
					    ddi_strategy_t _funcp));
#endif
int		_forward_chpoll	__PROTO ((o_dev_t _dev, int _events,
					  int _msec, ddi_chpoll_t _funcp));

void		_streams_open	__PROTO ((o_dev_t _dev, int _mode, int _flags,
					  __cred_t * _credp,
					  struct inode ** inodepp,
					  struct streamtab * _infop));
void		_streams_close	__PROTO ((o_dev_t _dev, int _mode, int _flags,
					  __cred_t * _credp,
					  __VOID__ * _private));
void		_streams_read	__PROTO ((o_dev_t _dev, IO * _iop,
					  __cred_t * _credp,
					  __VOID__ * _private));
void		_streams_write	__PROTO ((o_dev_t _dev, IO * _iop,
					  __cred_t * _credp,
					  __VOID__ * _private));
void		_streams_ioctl	__PROTO ((o_dev_t _dev, int _cmd,
					  __VOID__ * _arg, int mode,
					  __cred_t * _credp, int * _rvalp,
					  __VOID__ * _private));
int		_streams_chpoll	__PROTO ((o_dev_t _dev, int _events,
					  int _msec, __VOID__ * _private));

__EXTERN_C_END__

typedef struct {
	int	      *	cdev_flag;
	CON		cdev_con;
} cdevsw_t;

#define	CDEVSW_ENTRY(fl,op,cl,re,wr,io,ch,mm) \
	{ (fl), { (ch) == 0 ? DFCHR : DFCHR | DFPOL, 0, \
		  (driver_open_t) (op), (driver_close_t) (cl), 0, \
		  (driver_read_t) (re), (driver_write_t) (wr), \
		  (driver_ioctl_t) (io), 0, 0, 0, 0, (driver_poll_t) (ch) } }

#define	NULL_CDEVSW() \
	{ 0, { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 } }


typedef struct {
	int	      *	bdev_flag;
	CON		bdev_con;
} bdevsw_t;

#define	BDEVSW_ENTRY(fl,op,cl,st,pr,si) \
	{ (fl), { DFBLK, 0, (op), (cl), (st), 0, 0, 0, \
	  0, 0, 0, 0, 0 } }

#define	NULL_BDEVSW() \
	{ 0, { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 } }

#define	STREAMS_ENTRY(name) \
	{ & __DEVFLAG (name), { DFCHR | DFPOL, 0, \
		(driver_open_t) __CONCAT (name, openS), \
		(driver_close_t) __CONCAT (name, closeS), 0, \
		(driver_read_t) __CONCAT (name, readS), \
		(driver_write_t) __CONCAT (name, writeS), \
		(driver_ioctl_t) __CONCAT (name, ioctlS), 0, \
		0, 0, 0, (driver_poll_t) __CONCAT (name, chpollS) } }

#define	COH_OPEN(name, s) \
  __LOCAL__ void __CONCAT3 (name, open, s) \
	DEF ((o_dev_t dev, int mode, int flag, __cred_t * credp, \
		struct inode ** inodepp),\
	     (dev, mode, flag, credp, inodepp) o_dev_t dev; int mode; \
		int flag; __cred_t * credp; struct inode ** inodepp;)

#define	COH_CLOSE(name, s) \
  __LOCAL__ void __CONCAT3 (name, close, s) \
	DEF ((o_dev_t dev, int mode, int flag, __cred_t * credp, \
	      __VOID__ * private), \
	     (dev, mode, flag, credp, private) \
	      o_dev_t dev; int mode; int flag; __cred_t * credp; \
	      __VOID__ * private;)

#define	COH_READ(name, s) \
  __LOCAL__ void __CONCAT3 (name, read, s) \
	DEF ((o_dev_t dev, IO * iop, __cred_t * credp, __VOID__ * private), \
	     (dev, iop, credp, private) \
	      o_dev_t dev; IO * iop; __cred_t * credp; __VOID__ * private;)

#define	COH_WRITE(name, s) \
  __LOCAL__ void __CONCAT3 (name, write, s) \
	DEF ((o_dev_t dev, IO * iop, __cred_t * credp, __VOID__ * private), \
	     (dev, iop, credp, private) \
	      o_dev_t dev; IO * iop; __cred_t * credp; __VOID__ * private;)

#define	COH_IOCTL(name, s) \
  __LOCAL__ void __CONCAT3 (name, ioctl, s) \
	DEF ((o_dev_t dev, int cmd, __VOID__ * arg, int mode, \
	      __cred_t *credp, int * rvalp, __VOID__ * private), \
	     (dev, cmd, arg, mode, credp, rvalp, private) \
	      o_dev_t dev; int cmd; __VOID__ * arg; int mode; \
	      __cred_t * credp; int * rvalp; __VOID__ * private;)

#define	COH_STRATEGY(name, s) \
  __LOCAL__ void __CONCAT3 (name, strategy, s) \
	DEF ((BUF * buf), \
	     (buf) BUF * buf;)

#define	COH_CHPOLL(name, s) \
   __LOCAL__ int __CONCAT3 (name, chpoll, s) \
	DEF ((o_dev_t dev, int events, int msec, __VOID__ * private), \
	     (dev, events, msec, private) \
	      o_dev_t dev; int events; int msec; __VOID__ * private;)

#define	DECLARE_STREAMS(name) \
 extern struct streamtab __INFO (name); \
 COH_OPEN (name, S) { \
	_streams_open (dev, mode, flag, credp, inodepp, & __INFO (name)); \
 } \
 COH_CLOSE (name, S) { \
	_streams_close (dev, mode, flag, credp, private); \
 } \
 COH_READ (name, S) { \
	_streams_read (dev, iop, credp, private); \
 } \
 COH_WRITE (name, S) { \
	_streams_write (dev, iop, credp, private); \
 } \
 COH_IOCTL (name, S) { \
	_streams_ioctl (dev, cmd, arg, mode, credp, rvalp, private); \
 } \
 COH_CHPOLL (name, S) { \
	return _streams_chpoll (dev, events, msec, private); \
 }

#define	DECLARE_OPEN_CLOSE(name) \
  COH_OPEN (name,D) { \
	EXTERN_OPEN (name); \
	EXTERN_CLOSE (name); \
	_forward_open (dev, mode, flag, credp, inodepp, __OPEN (name), \
		       __CLOSE (name)); \
  }

#define	DECLARE_OPEN(name) \
  COH_OPEN (name,D) { \
	EXTERN_OPEN (name); \
	_forward_open (dev, mode, flag, credp, inodepp, __OPEN (name), \
		       NULL); \
  }

#define	DECLARE_CLOSE(name) \
  COH_CLOSE (name,D) { \
	EXTERN_CLOSE (name); \
	_forward_close (dev, mode, flag, credp, __CLOSE (name)); \
  }

#define	DECLARE_READ(name) \
  COH_READ (name,D) { \
	EXTERN_READ (name); \
	_forward_read (dev, iop, credp, __READ (name)); \
  }

#define	DECLARE_WRITE(name) \
  COH_WRITE (name,D) { \
	EXTERN_WRITE (name); \
	_forward_write (dev, iop, credp, __WRITE (name)); \
  }

#define	DECLARE_IOCTL(name) \
  COH_IOCTL (name,D) { \
	EXTERN_IOCTL (name); \
	_forward_ioctl (dev, cmd, arg, mode, credp, rvalp, __IOCTL (name)); \
  }

#define	DECLARE_STRATEGY(name) \
  COH_STRATEGY (name,D) { \
	EXTERN_STRATEGY (name); \
	_forward_strategy (buf, __STRATEGY (name)); \
  }

#define	DECLARE_CHPOLL(name) \
  COH_CHPOLL (name,D) { \
	EXTERN_CHPOLL (name); \
	return _forward_chpoll (dev, events, msec, __CHPOLL (name)); \
  }

#define	OPEN(name)		__CONCAT (name, openD)
#define CLOSE(name)		__CONCAT (name, closeD)
#define	READ(name)		__CONCAT (name, readD)
#define	WRITE(name)		__CONCAT (name, writeD)
#define	IOCTL(name)		__CONCAT (name, ioctlD)
#define	STRATEGY(name)		__CONCAT (name, strategyD)
#define	CHPOLL(name)		__CONCAT (name, chpollD)

/*
 * "drvl" and "drvn" are declared for us in <sys/con.h>. Note that the drvl []
 * table always has 32 entries to allow the patching hacks.
 */

#define	DECLARE_DRVL(name)	extern CON	__CONCAT (name, con);

#define	DRVL_ENTRY(name)	{ & __CONCAT (name, con) }

#define	NULL_DRVL()		{ 0 }

#endif	/* __COHERENT__ || defined (__MSDOS__) */


/*
 * Now default definitions for those things that are not overridden above.
 */

#if	! defined (DECLARE_STREAMS)
# define	DECLARE_STREAMS(name)	extern struct streamtab __INFO (name);
#endif

#if	! defined (DECLARE_MODULE)
# define	DECLARE_MODULE(name)	extern struct streamtab __INFO (name);
#endif

#if	! defined (DECLARE_OPEN) || ! defined (OPEN)
# define	DECLARE_OPEN(name)	EXTERN_OPEN (name);
# define	OPEN(name)		__OPEN (name)
#endif

#if	! defined (DECLARE_CLOSE) || ! defined (CLOSE)
# define	DECLARE_CLOSE(name)	EXTERN_CLOSE (name);
# define	CLOSE(name)		__CLOSE (name)
#endif

#if	! defined (DECLARE_READ) || ! defined (READ)
# define	DECLARE_READ(name)	EXTERN_READ (name);
# define	READ(name)		__READ (name)
#endif

#if	! defined (DECLARE_WRITE) || ! defined (WRITE)
# define	DECLARE_WRITE(name)	EXTERN_WRITE (name);
# define	WRITE(name)		__WRITE (name)
#endif

#if	! defined (DECLARE_IOCTL) || ! defined (IOCTL)
# define	DECLARE_IOCTL(name)	EXTERN_IOCTL (name);
# define	IOCTL(name)		__IOCTL (name)
#endif

#if	! defined (DECLARE_CHPOLL) || ! defined (CHPOLL)
# define	DECLARE_CHPOLL(name)	EXTERN_CHPOLL (name);
# define	CHPOLL(name)		__CHPOLL (name)
#endif

#if	! defined (DECLARE_MMAP) || ! defined (MMAP)
# define	DECLARE_MMAP(name)	EXTERN_MMAP (name);
# define	MMAP(name)		__MMAP (name)
#endif

#if	! defined (DECLARE_STRATEGY) || ! defined (STRATEGY)
# define	DECLARE_STRATEGY(name)	EXTERN_STRATEGY (name);
# define	STRATEGY(name)		__STRATEGY (name)
#endif

#if	! defined (DECLARE_PRINT) || ! defined (PRINT)
# define	DECLARE_PRINT(name)	EXTERN_PRINT (name);
# define	PRINT(name)		__PRINT (name)
#endif

#if	! defined (DECLARE_SIZE) || ! defined (SIZE)
# define	DECLARE_SIZE(name)	EXTERN_SIZE (name);
# define	SIZE(name)		__SIZE (name)
#endif

#if	! defined (DECLARE_INTR) || ! defined (INTR)
# define	DECLARE_INTR(name)	EXTERN_INTR (name);
# define	INTR(name)		__INTR (name)
#endif

#if	! defined (DECLARE_INIT) || ! defined (INIT)
# define	DECLARE_INIT(name)	EXTERN_INIT (name);
# define	INIT(name)		__INIT (name)
#endif

#if	! defined (DECLARE_START) || ! defined (START)
# define	DECLARE_START(name)	EXTERN_START (name);
# define	START(name)		__START (name)
#endif

#if	! defined (DECLARE_EXIT) || ! defined (EXIT)
# define	DECLARE_EXIT(name)	EXTERN_EXIT (name);
# define	EXIT(name)		__EXIT (name)
#endif

#if	! defined (DECLARE_HALT) || ! defined (HALT)
# define	DECLARE_HALT(name)	EXTERN_HALT (name);
# define	HALT(name)		__EXIT (halt)
#endif

#ifndef	CDEVSW_ENTRY

typedef struct {
	int	      *	cdev_flag;
	struct streamtab
		      *	cdev_stream;
	ddi_open_t	cdev_open;
	ddi_close_t	cdev_close;
	ddi_read_t	cdev_read;
	ddi_write_t	cdev_write;
	ddi_ioctl_t	cdev_ioctl;
	ddi_chpoll_t	cdev_chpoll;
	ddi_mmap_t	cdev_mmap;
} cdevsw_t;

#define	CDEVSW_ENTRY(fl,op,cl,re,wr,io,ch,mm) \
	{ (fl), 0, (op), (cl), (re), (wr), (io), (ch), (mm) }

#define	STREAMS_ENTRY(name) \
	{ & __DEVFLAG (name), & __INFO (name), 0, 0, 0, 0, 0, 0 }

#define	NULL_CDEVSW() \
	{ 0, 0, 0, 0, 0, 0, 0, 0 }

#endif	/* ! defined (CDEVSW_ENTRY) */

#ifndef	BDEVSW_ENTRY

typedef struct {
	int	      *	bdev_flag;
	ddi_open_t	bdev_open;
	ddi_close_t	bdev_close;
	ddi_strategy_t	bdev_strategy;
	ddi_print_t	bdev_print;
	ddi_size_t	bdev_size;
} bdevsw_t;

#define	BDEVSW_ENTRY(fl,op,cl,st,pr,si) \
	{ (fl), (op), (cl), (st), (pr), (si) }

#define	NULL_BDEVSW() \
	{ 0, 0, 0, 0, 0, 0 }

#endif	/* ! defined (BDEVSW_ENTRY) */


#ifndef	MODSW_ENTRY

typedef	struct {
	int	      *	mod_flag;
	struct streamtab
		      *	mod_stream;
} modsw_t;

#define	MODSW_ENTRY(name)	{ & __DEVFLAG (name), & __INFO (name) }

#define	NULL_MODSW()		{ 0, 0 }

#endif	/* ! defined (MODSW_ENTRY) */


#if	__BORLANDC__

/*
 * Under MS-DOS, we have to avoid disrupting the existing software. That means
 * we have to take care to chain to the appropriate previous handlers; given
 * that Borland C++ has support for this, interrupts under C++ are supported
 * using native facilities rather than a generic trap layer. A generic trap
 * layer should be doing similar things, of course.
 */

#define	__VECTOR(vec)	__CONCAT (vector, vec)
#define	__PREV(vec)	__CONCAT3 (vector, vec, _prev)

typedef	interrupt void (* intthunk_t)	__PROTO	((__ANY_ARGS__));

__EXTERN_C_BEGIN__

void	_chain_intr (intthunk_t _prev_int);	/* Borland C++ library */
void	CHECK_DEFER (void);

__EXTERN_C_END__


typedef	struct {
	int		int_vector;
	intthunk_t	int_thunk;
	intthunk_t    *	int_prev;
} intr_t;

#define	BEGIN_THUNK(vec,mask) \
  __LOCAL__ intthunk_t	__PREV (vec); \
  __LOCAL__ interrupt void __VECTOR (vec) \
	DEF ((__ANY_ARGS__), __ARGS (())) { \
		intmask_t	oldmask = __GET_BASE_MASK (); \
		pl_t		prev_pl; \
		if (__PREV (vec) != 0) \
			(* __PREV (vec)) (); \
		__SET_BASE_MASK (oldmask | (mask)); \
		__DDI_DKI_ENTER_INTERRUPT (); \
		prev_pl = spltimeout (); \
		__SEND_EOI (vec); \
		__CHEAP_ENABLE_INTS ();

#define	CALL_INTR(vec, unit, name)	(void) __INTR (name) (unix);

#define	END_THUNK(vec) \
		__CHEAP_DISABLE_INTS (); \
		__SET_BASE_MASK (oldmask); \
		splx (prev_pl); \
		if (ddi_cpu_data ()->dc_int_level == 1 && \
		    ddi_cpu_data ()->dc_ipl == plbase) \
			CHECK_DEFER (); \
		__DDI_DKI_LEAVE_INTERRUPT (); \
	}

#define	INTR_THUNK(vec, mask, name) \
		{ vec, __VECTOR (vec), & __PREV (vec) }

#elif	__COHERENT__

typedef	struct {
	int		int_vector;
	int		int_unit;
	intmask_t	int_mask;
	ddi_intr_t	int_handler;
} intr_t;

/*
 * The following code must mutate in time with the assembly-language interrupt
 * stub that calls the thunks!
 */

#define	BEGIN_THUNK(vec, mask) 
#define	CALL_INTR(vec, unit, name)
#define	END_THUNK(vec)

#define	INTR_THUNK(vec, unit, mask, name) \
		{ vec, unit, mask, __INTR (name) }

#else	/* ! __COHERENT__ */

#error	I dont know how to configure the interrupts for your system

#endif


typedef	ddi_init_t	init_t;
typedef	ddi_start_t	start_t;
typedef	ddi_exit_t	exit_t;
typedef	ddi_halt_t	halt_t;

extern	init_t		inittab [];
extern	unsigned int	ninit;

extern	start_t		starttab [];
extern	unsigned int	nstart;

extern	exit_t		exittab [];
extern	unsigned int	nexit;

extern	halt_t		halttab [];
extern	unsigned int	nhalt;

extern	cdevsw_t	cdevsw [];
extern	unsigned int	ncdevsw;

extern	bdevsw_t	bdevsw [];
extern	unsigned int	nbdevsw;

extern	modsw_t		modsw [];
extern	unsigned int	nmodsw;

extern	__major_t	_maxmajor;
extern	__major_t	_major [];
extern	__minor_t	_minor [];

extern	intr_t		inttab [];
extern	unsigned int	nintr;

#endif	/* ! defined (__SYS_CONFINFO_H__) */
