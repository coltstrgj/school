#include "calc.h"
#include <stdlib.h>
#include <time.h>

static bool seeded=false;

int random_number()
{
	if (!seeded) {
		srand((unsigned) time((long *) 0));
		seeded=true;
	}

	push(rand() / 32768.0);
	return SUCCESS;
}

static func_info fi(random_number, "rand", "random number");
