#include "calc.h"

int absolute_value()
{
	push(fabs(pop()));
	return SUCCESS;
}

static func_info fi(absolute_value, "abs", "absolute value");
