/* (-lgl
 *	Coherent 386 release 4.2
 *	Copyright (c) 1982, 1993 by Mark Williams Company.
 *	All rights reserved. May not be copied without permission.
 *	For copying permission and licensing info, write licensing@mwc.com
 -lgl) */
/***********************************************************************
 *  Module: haiioctl.h
 *  
 *  Definitions and declarations needed to implement and use the haiioctl
 *  call.
 *  
 *  Copyright (c) 1993 Christopher Sean Hilton All rights reserved.
 */

#ifndef __HAIIOCTL_H__
#define __HAIIOCTL_H__

#include <sys/haiscsi.h>
 
#define HAI_IOC		0x49414800	/* "\0HAI"  on intel machines */
#define HAIINQUIRY	(HAI_IOC | 1)	/* Inquiry Command */
#define HAIMDSNS0	(HAI_IOC | 2)	/* Group 0 Mode Sense */
#define HAIMDSLCT0	(HAI_IOC | 3)	/* Group 0 Mode Select */
#define HAIMDSNS2	(HAI_IOC | 4)	/* Group 2 Mode Sense */
#define HAIMDSLCT2	(HAI_IOC | 5)	/* Group 2 Mode Select */
#define HAIUSERCDB	(HAI_IOC | 6)	/* User Selected command (be careful) */

/***********************************************************************
 *  haiusercdb  --  Use this layout to get I/O Control info to or from
 *                  a particular device on the scsi bus.  Note well
 *                  that you will need to be the super user in order
 *                  to use the HAIUSERCDB I/O Control.
 */

typedef struct haiusercdb_s *haiusercdb_p;

typedef struct haiusercdb_s {
	cdb_t		cdb;		/* CDB you want to run */
	char		sensebuf[HAI_SENSELEN]; /* Sensebuf for returned errors */
	unsigned short	status;		/* Device Status after command */
	unsigned short	hastat;		/* Host Adapter Status after command */
	unsigned short	timeout;	/* Time to live */
	unsigned short	xferdir;	/* Transfer direction */
	size_t		buflen;		/* Buffer length */
	char		buf[0];		/* Start of buffer (C++ okay!?) */
} haiusercdb_t;

#endif	/* ! defined (__HAIIOCTL_H__) */
