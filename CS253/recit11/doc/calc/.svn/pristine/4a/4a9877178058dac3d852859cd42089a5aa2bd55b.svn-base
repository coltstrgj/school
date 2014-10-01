#include "calc.h"
#include <errno.h>

int gamma_fn()
{
	number x,y;
	extern int signgam;

	errno=0;
	x = pop();
	y = gamma(x);
	y = exp(y) * signgam;
	if (errno) {
		msg("Out of range");
		push(x);
		return FAILURE;
	}
	push(y);
	return SUCCESS;
}

static func_info fi(gamma_fn, "gamma", "gamma function");
