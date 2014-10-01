#include "calc.h"
#include <stdlib.h>

int compare(const void *va, const void *vb)
{
	const number a = * (const number *) va;
	const number b = * (const number *) vb;
	if (a<b)
		return -1;
	else if (a==b)
		return 0;
	else
		return 1;
}


int sort()
{
	qsort((char *) stack, (unsigned) stack_size, sizeof(number), compare);

	return SUCCESS;
}


static func_info fi(sort, "sort", "sort the stack");
