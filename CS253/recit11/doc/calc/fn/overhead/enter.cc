#include "calc.h"

int enter()
{
	number x;

	x = pop();
	push(x);
	push(x);
	return SUCCESS;
}

static func_info fi(enter, "enter", "enter");
