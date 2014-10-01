#include "calc.h"

extern fn gcd;

int ratio()
{
	int m;	/* the larger of the two numbers */
	int n;  /* the smaller of the two numbers */
	int g;  /* the gcd */

	m=(int) pop();
	n=(int) pop();

	push((number)n);
	push((number)m);
	gcd();
	g=(int) pop();

	push((number)(n/g));
	push((number)(m/g));
	return SUCCESS;
}

static func_info fi(ratio, "ratio", "normalize a ratio");
