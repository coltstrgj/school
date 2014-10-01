#include "calc.h"

extern void exponential();

int e()
{
	push(1.0);
	exponential();
	return SUCCESS;
}

static func_info fi(e, "E", "e");
