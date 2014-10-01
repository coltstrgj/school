#include "calc.h"
#include <errno.h>

int power()
{
	number x,y,z;

	x = pop();
	y = pop();

	errno=0;
	z = pow(y,x);

	if (errno!=0) {
		msg("Result out of bounds");
		push(y);
		push(x);
		return FAILURE;
	}
	push(z);
	return SUCCESS;
}

static func_info fi(power, "^", "exponentiation");
