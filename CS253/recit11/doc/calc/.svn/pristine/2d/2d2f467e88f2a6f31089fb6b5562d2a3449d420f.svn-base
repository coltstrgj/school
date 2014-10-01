#include "calc.h"

int binary_mode()
{
	extern int number_base;

	number_base = 2;
	set_current_mode();
	return SUCCESS;
}

extern const char *arbitrary_base_output(int base, number num, int width);

static func_info fi(binary_mode, "bin", "binary mode", arbitrary_base_output);
