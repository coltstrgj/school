#include "calc.h"

extern bool print_zeros;

const char *unsigned_output(int /* base */, number num, int width)
{
	static char buf[80];

	sprintf(buf, print_zeros ? "%.*lu" :"%*lu", width, (long) num);
	return buf;
}

static func_info fi(set_current_mode, "unsigned", "unsigned mode", unsigned_output);
