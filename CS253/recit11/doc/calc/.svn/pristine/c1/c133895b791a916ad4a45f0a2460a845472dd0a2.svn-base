#include "calc.h"

int logarithm10()
{
	number x;

	x = pop();
	if (x<=0) {
		msg("Can't take log of non-positive number");
		push(x);
		return FAILURE;
	}
	push(log10(x));
	return SUCCESS;
}

static func_info fi(logarithm10, "log10", "logarithm base 10");
