#include "calc.h"
#include <math.h>

extern int multiply(number x, number y, number *z);

int perm()
{
	double	result;
	double	n;
	double  r;
	double	i;

	r=pop();
	n=pop();
	if (! ((floor(n)>=0) && (floor(r)>=0) && (floor(r)<=n)) ) {
		msg("for Pn:r n>=0 and r>=0 and r<=n");
		push((number)n);
		push((number)r);
		return FAILURE;
	}
	r=floor(r);
	n=floor(n);
	result=1.0;
	for (i=n-r+1; i<=n; i++) {
		if (multiply(result, i, &result) == FAILURE) {
			msg("overflow in permutation");
			push((number) result);
			return FAILURE;
		}
	}
	push((number)result);
	return SUCCESS;
}

static func_info fi(perm, "P", "permutations");
