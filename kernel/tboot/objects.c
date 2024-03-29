/* objects.c -- routines for handling different object formats.
 * Currently, only COFF and COHERENT l.out are supported.
 */
#include <sys/inode.h>
#include <sys/types.h>
#include <l.out.h>
#include <coff.h>	/* COFF */

#include "tboot.h"

/* Extract information from an object file that describes how to
 * load an executable.
 * The magic number of the file is in "magic".
 * The object file's inode is in "ip".
 *
 * The information needed is extracted into "table".
 * The value for the data segment is put in "data_seg".
 *
 * Returns TRUE if the needed information could be extracted, FALSE ow.
 */

int
object2load(magic, ip, table, data_seg)
	uint16 magic;
	struct inode *ip;
	struct load_segment table[];
	uint16 *data_seg;
{
	int retval;

	switch (magic) {
	/* Is this an i386 COFF executable?  */
	case I386MAGIC:
		VERBOSE( puts("COFF!  COFF!\r\n"); );
		retval = 
			coff2load(ip, table, data_seg);
		break;
		
	/* Is this an l.out executable?  */
	case L_MAGIC:
		VERBOSE( puts("l.out!\r\n"); );
		retval =
			lout2load(ip, table, data_seg);
		break;
	
	default:
		retval = FALSE;
		break;
	} /* switch (magic) */

	return (retval);
} /* object2load() */


/* Look up symbol(s) in an object file. 
 * searches  the name list  (symbol table) of  the load module
 * "filename" for each symbol in the array pointed to by "nlp".
 *
 * nlp points to an array of nlist structures, terminated by a
 * structure with a null string as its n_name member.
 *
 * If "filename" is not a load module or has had its symbol table
 * stripped, all returned n_type and n_value entries will be zero.
 *
 */

uint16
object_nlist(magic, filename, symbol)
	uint16 magic;
	char *filename;
	char *symbol;
{
	uint32 tmp;
	unsigned int retval;		/* Return value.  */

	switch (magic) {
	/* Is this an i386 COFF executable?  */
	case I386MAGIC:
		/* Check that offset into data segment is < 64K.  */
		if ((tmp = wrap_coffnlist(filename, symbol)) > MAXUINT16) {
			puts("object_nlist(): ERROR: Symbol ");
			puts(symbol);
			puts(" will not fit into 16 bits.\r\n");
			puts(symbol); puts("=");
			print32(tmp);
			puts("\r\n");
			
			retval = 0;
		} else {
			retval = (uint16) tmp;
		}
		break;
		
	/* Is this an l.out executable?  */
	case L_MAGIC:
		retval = wrap_l_out_nlist(filename, symbol);
		break;
	
	default:
		break;
	} /* switch (magic) */

	return (retval);
} /* object_nlist() */


/* Determine the value for sys_base based on the type of the load file.  */
uint16
object_sys_base(magic)
	int magic;
{
	uint16 retval;

	switch (magic) {
	/* Is this an i386 COFF executable?  */
	case I386MAGIC:
		retval = COFF_SYS_BASE;
		break;
		
	/* Is this an l.out executable?  */
	case L_MAGIC:
		retval = DEF_SYS_BASE;
		break;
	
	default:
		break;
	} /* switch (magic) */

	return(retval);
} /* object_sys_base() */

#ifdef TEST
main()
{
	printf("pipdev: %x", object_nlist(I386MAGIC, "/at386", "pipedev"));
} /* main () */

#endif /* TEST */
