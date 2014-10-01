#include "calc.h"
#include <errno.h>

int exponential()
{
	number x, z;

	x = pop();
	errno=0;
	z = exp(x);
	if (errno) {
		msg("Out of range");
		push(x);
		return FAILURE;
	}
	push(z);
	return SUCCESS;
}

static func_info fi(exponential, "exp", "exponential");
