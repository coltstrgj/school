#include "calc.h"

extern int precision;

int decimal_mode()
{
	extern int number_base;

	number_base = 10;
	set_current_mode();
	return SUCCESS;
}

const char *decimal_output(int /* base */, number num, int width)
{
	static char buf[80];

	sprintf(buf, "%*.*lg", width, precision+1, num);
	return buf;
}

static func_info decimal_info(decimal_mode, "dec", "decimal mode", decimal_output);
