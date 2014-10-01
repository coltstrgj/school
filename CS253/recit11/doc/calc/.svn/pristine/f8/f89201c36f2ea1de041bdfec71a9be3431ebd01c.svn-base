#include "calc.h"

int square_root()
{
	number x;

	x = pop();
	if (x<0) {
		msg("Can't take square root of negative number");
		push(x);
		return FAILURE;
	}
	push(sqrt(x));

	return SUCCESS;
}

static func_info fi(square_root, "sqrt", "square root");
