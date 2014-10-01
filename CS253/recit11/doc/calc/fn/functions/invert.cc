#include "calc.h"

int invert()
{
	number x;

	x = pop();
	if (x==0) {
		msg("Can't divide by zero");
		push(x);
		return FAILURE;
	}
	push(1/x);
	return SUCCESS;
}

static func_info fi(invert, "inv", "1/x");
