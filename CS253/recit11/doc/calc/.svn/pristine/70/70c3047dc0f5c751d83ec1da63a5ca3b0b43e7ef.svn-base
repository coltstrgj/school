#include "calc.h"

#define returnfactor(k) { push(k); push(n/k); return SUCCESS; }

int factor()
{
	int	fact;
	int	n;

	n= (int) pop();

	if (n<2) {
		push((number)1.0);
		return FAILURE;
		}

	if (n%2==0) returnfactor(2.0);
	if (n%3==0) returnfactor(3.0);
	if (n%5==0) returnfactor(5.0);

	fact=7;
	while (fact*fact <= n) {
		if (n%fact==0) returnfactor((number)fact);
		fact+=4;
		if (n%fact==0) returnfactor((number)fact);
		fact+=2;
		if (n%fact==0) returnfactor((number)fact);
		fact+=4;
		if (n%fact==0) returnfactor((number)fact);
		fact+=2;
		if (n%fact==0) returnfactor((number)fact);
		fact+=4;
		if (n%fact==0) returnfactor((number)fact);
		fact+=6;
		if (n%fact==0) returnfactor((number)fact);
		fact+=2;
		if (n%fact==0) returnfactor((number)fact);
		fact+=6;
		}
	if (n>1) returnfactor((number)n);
	returnfactor((number)1.0);
}

static func_info fi(factor, "factor", "factor");
