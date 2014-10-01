#include "calc.h"

int octal_mode()
{
	extern int number_base;

	number_base = 8;
	set_current_mode();
	return SUCCESS;
}

extern const char *arbitrary_base_output(int base, number num, int width);

static func_info fi(octal_mode, "oct", "octal mode", arbitrary_base_output);
