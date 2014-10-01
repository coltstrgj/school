#include "calc.h"

int hyper_tangent()
{
	push(tanh(pop()));

	return SUCCESS;
}

static func_info fi(hyper_tangent, "tanh", "hyperbolic tangent");
