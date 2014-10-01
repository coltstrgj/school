#include "calc.h"

extern double angle_multiplier;

int cosine()
{
	push(cos(angle_multiplier*pop()));
	return SUCCESS;
}

static func_info fi(cosine, "cos", "cosine");
