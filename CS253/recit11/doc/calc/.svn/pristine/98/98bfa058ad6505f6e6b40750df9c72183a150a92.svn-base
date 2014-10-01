#include "calc.h"

const char *split_octal_output(int /* base */, number num, int /* width */)
{
	static char buf[80];
	char *bp=buf;

	long l = (long) num;
	for (int i=3; i>=0; i--) {
		int c = (l >> (i*8)) & 0377;
		bp += sprintf(bp, "%.3o", c);
		if (i>0)
			*bp++ = ' ';
	}
	*bp = '\0';
	return buf;
}

static func_info fi(set_current_mode, "soct", "split octal mode", split_octal_output);
