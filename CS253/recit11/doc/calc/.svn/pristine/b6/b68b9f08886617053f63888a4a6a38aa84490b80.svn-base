#include "calc.h"
#include <math.h>

/*
 * Convert to h.mmss to fractional hours.
 * For example, convert 1.3000 to 1.5.
 */
int hours()
{
	number x, hour, min, sec;

	x = pop();
	hour = floor(x);
	x = (x-hour)*100;
	min = floor(x);
	x = (x-min)*100;
	sec = x;
	push(hour + min/60 + sec/(60*60));
	return SUCCESS;
}

static func_info fi(hours, "hours", "h.mmss -> hours");
