#include "calc.h"

double angle_multiplier = 1.0;		/* default mode is radians */
extern int pi();

int degrees()
{
	pi();				/* get pi on stack for later use */
	angle_multiplier = pop()/180.0;
	return SUCCESS;
}

static func_info fi(degrees, "deg", "degrees mode");
