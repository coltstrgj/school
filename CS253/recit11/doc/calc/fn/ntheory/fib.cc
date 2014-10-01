#include "calc.h"

int fib()
{
	int i;
	double a, b;
	double n;

	a=1.0;
	b=1.0;

	n=pop();
	if (floor(n)<=0) {
		msg("Fibonacci number is undefined for non-positive integers");
		push((number)n);
		return FAILURE;
	}
	n=floor(n);
	for(i=3; i<=n; i++) {
		b += a;
		a = b-a;
	}
	push((number)b);
	return SUCCESS;
}

static func_info fi(fib, "F", "fibonacci number");
