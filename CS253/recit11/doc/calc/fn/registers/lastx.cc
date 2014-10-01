#include "calc.h"

int lastx()
{
	number x;

	if (recall("lastx", &x) == FAILURE) {
		msg("There is no last x");
		return FAILURE;
	}
	push(x);

	return SUCCESS;
}

static func_info fi1(lastx, "lx", "last x");
static func_info fi2(lastx, "lastx", "last x");
