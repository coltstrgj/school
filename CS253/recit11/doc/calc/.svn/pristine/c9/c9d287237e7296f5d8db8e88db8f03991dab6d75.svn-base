#include "calc.h"

int gcd()
{
	int m;	/* the larger of the two numbers */
	int n;  /* the smaller of the two numbers */
	int t;  /* a temporary */

	m=(int) fabs(pop());
	n=(int) fabs(pop());

	if (m<n) {
		t=m;
		m=n;
		n=t;
	}
	while (n>0) {
		t=m%n;
		m=n;
		n=t;
	}
	if (m<1)
		m=1;
	push((number)m);
	return SUCCESS;
}

static func_info fi(gcd, "gcd", "greatest common denominator");
