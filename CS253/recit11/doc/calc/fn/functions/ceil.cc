#include "calc.h"

int ceiling()
{
	push(ceil(pop()));
	return SUCCESS;
}

static func_info fi(ceiling, "ceil", "ceiling");
