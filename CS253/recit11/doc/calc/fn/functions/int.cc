#include "calc.h"
#include <math.h>

int integer_part()
{
	number ipart;

	(void) modf(pop(), &ipart);

	push(ipart);
	return SUCCESS;
}

static func_info fi(integer_part, "int", "integer part");
