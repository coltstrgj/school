#include "calc.h"

extern double angle_multiplier;

int arccosine()
{
	push(acos(pop())/angle_multiplier);
	return SUCCESS;
}

static func_info fi(arccosine, "acos", "arc cosine");
