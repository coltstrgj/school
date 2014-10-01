#include "calc.h"

extern double angle_multiplier;

int tangent()
{
	push(tan(angle_multiplier*pop()));

	return SUCCESS;
}

static func_info fi(tangent, "tan", "tangent");
