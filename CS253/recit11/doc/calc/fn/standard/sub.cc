#include "calc.h"

int subtract()
{
	number x,y;

	x = pop();
	y = pop();

	push (y-x);

	return SUCCESS;
}

static func_info fi(subtract, "-", "subtraction");
