#include "calc.h"

int infinity()
{
	push((number) HUGE_VAL);
	return SUCCESS;
}

static func_info fi(infinity, "infinity", "infinity");
