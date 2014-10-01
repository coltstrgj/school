#include "calc.h"

int fn_or()
{
	long x,y;

	x = (long) pop();
	y = (long) pop();
	push((number) (x | y));
	return SUCCESS;
}

static func_info fi(fn_or, "|", "bitwise or");
