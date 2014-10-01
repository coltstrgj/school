#include "calc.h"

extern int gcd(), exchange(), fn_divide(), fn_multiply();

int lcm()
{
	number m;	/* the larger of the two numbers */
	number n;  /* the smaller of the two numbers */

	m=pop();
	n=pop();
	push(n);
	push(m);
	if (gcd() == FAILURE)
		return FAILURE;
	push(n);
	exchange();
	if (fn_divide() == FAILURE)
		return FAILURE;
	push(m);
	if (fn_multiply() == FAILURE)
		return FAILURE;
	return SUCCESS;
}

static func_info fi(lcm, "lcm", "least common multiple");
