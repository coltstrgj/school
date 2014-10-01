#include "calc.h"
#include <signal.h>

int divide(number x, number y, number *z);

int fn_divide()
{
	number x, y, z;

	x = pop();
	if (x==0) {
		msg("Can't divide by zero");
		push(x);
		return FAILURE;
	}
	y = pop();
	if (divide(x, y, &z)==FAILURE) {
		msg("out of range");
		push(y);
		push(x);
		return FAILURE;			/* signal error */
	}

	push(z);
	return SUCCESS;
}

static bool signal_occured;

static void catch_signal(int foo)
{
	foo=foo;
	signal_occured=true;
}

int divide(number x, number y, number *z)
{
	if (x==0)				/* divide by 0 may be special */
		return FAILURE;			/* SIGDIV0 or something */
	signal(SIGFPE, catch_signal);
	signal_occured=false;
	*z = y/x;
	return signal_occured ? FAILURE : SUCCESS;
}


static func_info fi(fn_divide, "/", "division");
