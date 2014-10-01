#include "calc.h"

int reset()
{
	set_default_status();
	return SUCCESS;
}

static func_info fi(reset, "reset", "reset to power-on values");
