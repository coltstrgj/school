#include "calc.h"

int logarithm()
{
	number x;

	x = pop();
	if (x<=0) {
		msg("Can't take log of non-positive number");
		push(x);
		return FAILURE;
	}
	push(log(x));
	return SUCCESS;
}

static func_info fi(logarithm, "ln", "natural log");
