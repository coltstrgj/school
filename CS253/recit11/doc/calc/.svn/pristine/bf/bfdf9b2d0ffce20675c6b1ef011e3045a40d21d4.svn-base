#include "calc.h"

const char *ascii_output(int /* base */, number num, int /* width */)
{
	int c, i;
	long l;
	bool got_one;
	char *bp;
	static char buf[256];

	l = (long) num;
	got_one = false;
	bp = buf;
	for (i=3; i>=0; i--) {
		c = (l >> (i*8)) & 0377;

		if (c!=0) got_one=true;
		if (c==0 && i>0 && !got_one) {	/* no leading zeros */
			*bp++ = ' ';
			*bp++ = ' ';
			*bp++ = ' ';
			continue;
		}

		/* If high bit set, print a bit */
		*bp++ = c>=128 ? '.' : ' ';
		c &= 0177;
			
		if (c>=32 && c<=126) {		/* printable? */
			*bp++ = ' ';
			*bp++ = c;
		} else {			/* ctl char is ^x */ 
			*bp++ = '^';
			*bp++ = c ^ 0100;
		}
	}
	*bp = '\0';				/* cork off string */
	return buf;
}

static func_info fi(set_current_mode, "ascii", "ascii mode", ascii_output);
