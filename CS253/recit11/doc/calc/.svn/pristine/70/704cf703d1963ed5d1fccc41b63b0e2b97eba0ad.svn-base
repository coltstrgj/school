#include "calc.h"
#include <signal.h>

int multiply(number x, number y, number *z);

int fn_multiply()
{
	number z;

	number x = pop();
	number y = pop();

	if (multiply(x, y, &z) == FAILURE) {
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


int multiply(number x, number y, number *z)
{
	signal(SIGFPE, catch_signal);
	signal_occured=false;
	*z = x*y;
	return signal_occured ? FAILURE : SUCCESS;
}

static func_info fi(fn_multiply, "*", "multiplication");
