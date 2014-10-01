#include "calc.h"

int fn_delete()
{
	char name[80];

	printw("Delete register: ");
	get_str(name);

	if (delete_reg(name) == FAILURE) {
		msg("Can't delete register \"%s\"", name);
		return FAILURE;
	}

	return SUCCESS;
}

static func_info fi(fn_delete, "delreg", "delete register");
