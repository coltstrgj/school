#include "calc.h"

extern double angle_multiplier;

int arcsine()
{
	push(asin(pop())/angle_multiplier);
	return SUCCESS;
}

static func_info fi(arcsine, "asin", "arc sine");
