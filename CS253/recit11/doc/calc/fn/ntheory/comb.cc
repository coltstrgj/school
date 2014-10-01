#include "calc.h"
#include <math.h>

extern number perm(), fact();
extern fn fn_divide;

int comb()
{
	double  r;

	r=floor(pop());
	push((number)r);

	if (perm()==FAILURE)
		return FAILURE;

	push((number)r);
	if (fact()==FAILURE)
		return FAILURE;
	return fn_divide();
}

static func_info fi(comb, "C", "combinations");
