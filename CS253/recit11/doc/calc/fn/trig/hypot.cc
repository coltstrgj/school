#include "calc.h"

int hypotenuse()
{
	push(hypot(pop(), pop()));
	return SUCCESS;
}

static func_info fi(hypotenuse, "hypot", "Euclidean distance");
