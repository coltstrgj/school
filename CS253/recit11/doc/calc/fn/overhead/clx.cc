#include "calc.h"

int clx()
{
	(void) pop();
	return SUCCESS;
}

static func_info fi(clx, "clx", "clear x");
