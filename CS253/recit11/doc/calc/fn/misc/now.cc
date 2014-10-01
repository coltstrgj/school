#include "calc.h"
#include <time.h>

int now()
{
	push((number) (time((long *) 0)));
	return SUCCESS;
}

static func_info fi(now, "now", "seconds since 1970");
