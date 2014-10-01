#include "calc.h"

int mod_fn()
{
	number x,y;

	x = pop();
	y = pop();

	push(fmod(y,x));
	return SUCCESS;
}

static func_info fi1(mod_fn, "mod", "modulus");
static func_info fi2(mod_fn, "%", "modulus");
