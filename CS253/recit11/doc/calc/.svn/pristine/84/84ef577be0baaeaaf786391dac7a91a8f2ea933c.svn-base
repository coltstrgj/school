#include "calc.h"
#include <time.h>
#include <string.h>

int print_date()
{
	char buf[30];
	long now = time((long *) 0);		/* current time */
	strcpy(buf, ctime(&now));		/* into our buffer */
	buf[24]='\0';				/* lose the newline */
	msg(buf);				/* display it */
	return SUCCESS;
}

static func_info fi(print_date, "date", "print the date");
