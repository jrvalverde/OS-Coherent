/ Startup.s -- initilization code for any tertiary boot program.
/
/ La Monte H. Yarroll <piggy@mwc.com>, September 1991
/

/ RBOOTS is set exactly 128K below the top of 640K.
/ One day, RBOOTS should be dynamicly determined based on the size of
/ available memory.  If you modify RBOOTS, be sure to update it in tboot.h
/ as well.
	RBOOTS	= 0x8000		/ New segement for boot program.
	JMPF	= 0xEA			/ jump far, direct
	SEGSIZ	= 0xffff		/ Size of a whole segment.
	NSTK	= 0x2000		/ # of bytes of stack.
	BLOCK	= 0x200			/ # of bytes in a disk block
	DIRSIZE	= 14			/ Size of a file name.
	SIZEOFSDAT = 23			/ sizeof(seconddat)
	SECONDDAT = 0x01E7		/ Offset of useful data in secondary boot.
	CR	= 0x0d			/ Carriage return
	LF	= 0x0a			/ Line Feed
	NUL	= 0x00			/ NUL (for terminating strings)

	/ Interrupts.
	MON	= 0x00		/ Invoke BIOS monitor.
	KEYBD	= 0x16		/ Keyboard software interrupt.
	REBOOT	= 0x19		/ Reboot through BIOS.
	
	
	NTRK	= 40		/ Number of tracks on a floppy.
	NSPT	= 9		/ Number of sectors per track on a floppy.
	NHD	= 1		/ Number of heads per drive on a floppy.

	.bssd
stack:	.blkb	NSTK	/ Local Stack

	.shri
	.blkb	0x100	/ Symbol "begin" must be at offset 0x100 from
begin:			/ the beginning of the code segment--secondary
			/ boot jumps here.
	/ Upon entry ds points at the secondary boot data segment,
	/ si points at the data we want,
	/ and es points at our data segment.

	mov	di, $seconddat
	mov	cx, $SIZEOFSDAT
	cld
	rep
	movsb	/ Copy disk configuration information to our own segment.

	/ Create a nice, safe stack.
	mov	bp, $stack+NSTK
	mov	ax, es
	mov	ss, ax
	mov	sp, bp
	
	push	es	/ Save location of data segment from secondary boot.

	/ Move the tertiary boot to high memory.
	call	moveme
	
	add	sp, $2	/ Throw away old data segment.

	/ Set up the new stack.

	mov	bp, $stack+NSTK
	mov	ax, es
	mov	ss, ax
	mov	sp, bp


	.byte	JMPF		/ Jump to the relocated code.
	.word	entry
	.word	RBOOTS

entry:	call	main_

/ Aargh!  main() returned!  Wait for a keystroke and then reboot.

	push	$keymsg
	call	puts_
0:	movb	ah, $1	/	while (!iskey()) {
	int 	KEYBD	/		/* Scan the keyboard.  */
	je	0b	/	}

			/	do {
1:	movb	ah, $0	/		getch();
	int 	KEYBD	/		/* Read the key.  */
	movb	ah, $1	/	} while (iskey())
	int 	KEYBD	/		/* Scan the keyboard for another key. */
	jne	1b	/	

	int	REBOOT	/ Reboot through the BIOS. 

	.shrd
keymsg:	
	.byte	CR
	.byte	LF
	.ascii	"Press any key to reboot."
	.byte	CR
	.byte	LF
	.byte	NUL

////////
/
/ Move tertiary boot to high memory.
/ Take one parameter--a word on the stack pointing to the current
/ data segment.
/
/ As a side effect, this sets ds to the new data segment in high memory.
/
////////
	.shri
moveme:
	mov	bp, sp	/ For parameter lookups.

	/ Move the code segment.
	push	cs
	pop	ds
	xor	si, si		/ Point ds:si at loaded code segment.
	mov	ax, $RBOOTS
	mov	es, ax
	xor	di, di		/ Point es:di at where we want to be.
	mov	cx, $SEGSIZ	/ Move a maximal segment.
	cld
	rep
	movsb

	/ Calculate location of new data segment.
	mov	ax, 2(bp)
	push	cs		/ Fetch the code segment.
	pop	bx
	sub	ax, bx		/ Calculate offset to data segment.
	add	ax, $RBOOTS	/ Calculate the new data segment.
	
	/ Move the data segment.
	mov	ds, 2(bp)
	xor	si, si		/ Point ds:si at loaded data segment
	mov	es, ax
	xor	di, di		/ Point es:di at where we want to be.
	mov	cx, $SEGSIZ	/ Move a maximal segment.
	cld
	rep
	movsb

	/ Set the new data segment appropriately.
	push	es
	pop	ds
	mov	myds_, ds
	ret	/ routine moveme

/ Shared data segment (initialized)
	.shrd

	.globl	myds_
myds_:	.word	0	/ Place to communicate ds to C programs.

/ Variables nbuf, traks, sects, and heads MUST appear in this order.
	.globl	seconddat
seconddat:	/ Data extracted from secondary boot data segment.
	.globl	nbuf_
nbuf_:
nbuf:	.blkb	DIRSIZE

/ Defaults for all the following parameters match a floppy disk.
	.globl	traks
	.globl	traks_
traks_:
traks:	.word	NTRK	/ Number of cylinders on drive we're booting off of.
	.globl	sects
	.globl	sects_
sects_:
sects:	.byte	NSPT	/ Number of sectors per track for our drive.
	.globl	heads
	.globl	heads_
heads_:
heads:	.byte	NHD	/ Number of heads on drive we're booting off of.

	.globl	drive
	.globl	drive_
drive_:
drive:	.byte	0	/ Drive our partition resides upon.
	.globl	first
	.globl	first_
first_:
first:	.word	0	/ First block of our partition (?)
	.word	0
