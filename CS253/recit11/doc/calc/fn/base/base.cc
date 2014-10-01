#include "calc.h"
#include <ctype.h>
#include <string.h>

int base()
{
	extern int number_base;
	int i;

	printw("Number base? ");
	i = getint();

	if (i<2 || i>36) {
		msg("Base must be 2<=base<=36");
		return FAILURE;
	}
	number_base = i;

	set_current_mode();
	return SUCCESS;
}

extern int print_zeros, precision;

const char *arbitrary_base_output(int base, number num, int width)
{
	const char digits[]="0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	char buf[100], *bufp;
	static char outbuf[100];
	int i;
	unsigned long numb;
	number dummy;

	outbuf[0] = '\0';

	/* Generate digits to the left of the radix point */
	if (num>=0)
		numb = (unsigned long) num;
	else {
		numb = (unsigned long) -num;
		strcat(outbuf+strlen(outbuf), "-");
	}

	bufp = &buf[sizeof(buf)];
	*--bufp = '\0';
	while (numb>0) {
		*--bufp = digits[numb % base];
		numb /= base;
	}

	/* Give them at least a zero! */
	if (!*bufp)
		*--bufp = digits[0];

	/* Add leading zeros */
	if (print_zeros)
		while (bufp+width  < &buf[sizeof(buf)])
			*--bufp = digits[0];
	

	/* Put the digits into outbuf where they belong */
	strcat(outbuf+strlen(outbuf), bufp);

	/* Generate fractional part */
	if (num < 0)
		num = -num;
	num = modf(num, &dummy);	/* just get frac part */
	if (num) {
		strcat(outbuf+strlen(outbuf), ".");
		for (i=0; i<precision; i++) {
			num = modf(num, &dummy);	/* just get frac part */
			num *= base;
			outbuf[strlen(outbuf)+1] = '\0';
			outbuf[strlen(outbuf)] = digits[(int) num];
		}
	}

	return outbuf;
}

static func_info fi(base, "base", "number base", arbitrary_base_output);
