#include "calc.h"
#include <string.h>

int fn_store()
{
	char name[80];
	number x;

	printw("Store in register: ");
	get_str(name);
	if (strcmp(name, "")==0)
		return SUCCESS;

	x = push(pop());		/* get top-of-stack */

	if (store(name, x) == FAILURE) {
		msg("Can't store into register \"%s\"", name);
		return FAILURE;
	}

	return SUCCESS;
}

static func_info fi(fn_store, "sto", "store to register");
