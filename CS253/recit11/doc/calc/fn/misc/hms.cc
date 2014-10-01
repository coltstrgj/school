#include "calc.h"
#include <math.h>

/*
 * Convert fractional hours to h.mmss.
 * For example, convert 1.5 to 1.3000
 */
int hms()
{
	number x, hours, min, sec;

	x = pop();

	x = modf(x, &hours); x *= 60.0;
	x = modf(x, &min); x *= 60.0;
	sec = x;
	push(hours + min/100 + sec/10000);

	return SUCCESS;
}

static func_info fi(hms, "hms", "hours -> h.mmss");
