#include "calc.h"
#include <time.h>

const char *time_output(int /* base */, number num, int /* width */)
{
	static char buf[80];

	long l = (long) num;			/* get time as integer */
	sprintf(buf, "%.24s", ctime(&l)); /* return time with no nl */
	return buf;
}

static func_info fi(set_current_mode, "time", "time mode", time_output);
