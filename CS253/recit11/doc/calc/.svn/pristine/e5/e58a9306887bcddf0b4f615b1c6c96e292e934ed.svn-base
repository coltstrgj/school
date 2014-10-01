#include "calc.h"

int hex_mode()
{
	extern int number_base;

	number_base = 16;
	set_current_mode();
	return SUCCESS;
}

extern const char *arbitrary_base_output(int base, number num, int width);

static func_info fi(hex_mode, "hex", "hex mode", arbitrary_base_output);
