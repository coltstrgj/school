#include "calc.h"

extern double angle_multiplier;

int arctangent()
{
	push(atan(pop())/angle_multiplier);
	return SUCCESS;
}

static func_info fi(arctangent, "atan", "arc tangent");
