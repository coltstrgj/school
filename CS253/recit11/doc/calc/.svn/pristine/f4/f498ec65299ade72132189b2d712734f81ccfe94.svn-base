#include "calc.h"

int zero()
{
	extern bool print_zeros;

	print_zeros = !print_zeros;

	if (print_zeros)
		msg("Leading zeros will be printed");
	else
		msg("Leading zeros will not be printed");

	return SUCCESS;
}

static func_info fi(zero, "zero", "leading zero control");
