#include "calc.h"

/* LINTLIBRARY */

extern int number_base;
extern int precision;
extern bool print_zeros;

const char *number_to_string(number num, int width)
{
	/* Is this an output routine? */
	return (*current_mode->output)(number_base, num, width);
}
