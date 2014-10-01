#include "calc.h"
#include <string.h>

int fn_recall()
{
	char name[80];
	number x;

	printw("Recall from register: ");
	get_str(name);
	if (strcmp(name, "")==0)
		return SUCCESS;

	if (recall(name, &x) == FAILURE) {
		msg("No such register \"%s\"", name);
		return FAILURE;
	}
	push(x);

	return SUCCESS;
}

static func_info fi(fn_recall, "rcl", "recall from register");
