#include "calc.h"

const char *split_hex_output(int /* base */, number num, int /* width */)
{
	static char buf[80];
	char *bp;
	long l;
	int i,c;

	bp = buf;
	l = (long) num;
	for (i=3; i>=0; i--) {
		c = (l >> (i*8)) & 0377;
		sprintf(bp, "%.2X", c);
		bp+=2;
		if (i>0)
			*bp++ = ' ';
	}
	*bp = '\0';
	return buf;
}

static func_info fi(set_current_mode, "shex", "split_hex mode", split_hex_output);
