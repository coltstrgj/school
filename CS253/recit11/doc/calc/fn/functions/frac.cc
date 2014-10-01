#include "calc.h"
#include <math.h>

int fractional_part()
{
	number fpart, ipart;

	fpart = modf(pop(), &ipart);

	push(fpart);
	return SUCCESS;
}

static func_info fi(fractional_part, "frac", "fractional part");
