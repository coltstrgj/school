#include "calc.h"
#include <ctype.h>

int stacksize()
{
	extern int stack_max;
	int i;

	printw("Stack size? ");
	i = getint();

	if (i<=0 || i>stack_max) {
		msg("Out of range");
		return FAILURE;
	}

	stack_size = i;

	return SUCCESS;
}

static func_info fi(stacksize, "ss", "stack size");
