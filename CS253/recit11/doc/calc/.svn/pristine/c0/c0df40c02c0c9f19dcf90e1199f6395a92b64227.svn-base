#include "calc.h"
#include <math.h>

extern int multiply(number x, number y, number *z);

int fact()
{
	double	result;
	double	n;
	double	i;

	n=pop();
	if (floor(n)<0) {
		msg("Factorial undefined for negative integers");
		push((number)n);
		return FAILURE;
		}
	n=floor(n);
	result=1.0;
	for(i=2; i<=n; i++) {
		if (multiply(result, i, &result) == FAILURE) {
			msg("overflow in factorial");
			push((number) result);
			return FAILURE;
			}
		}
	push((number)result);
	return SUCCESS;
}

static func_info fi(fact, "!", "factorial");
