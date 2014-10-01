#include "calc.h"
#include <string.h>

void itor(char *buf, long integer);

const char *roman_output(int /* base */, number num, int /* width */)
{
	static char buf[80];
	long l;

	l = (long) num;
	itor(buf, l);
	return buf;
}

char *onedigit(int pos, int digit);

void itor(char *buf, long integer)
{
	register int pos, len;
	char	digits[128], adigit[128];
	
	if (integer<0) {
		*buf++ = '-';
		integer = -integer;
	}

	if (integer >= 4000) {
		sprintf(buf, "%ld", integer);
		return;
	}

	sprintf(digits, "%ld", integer);
	len = strlen(digits);

	for (pos=0; pos<len; pos++) {
		strcpy(adigit, onedigit(len-pos-1, digits[pos]-'0'));
		strcpy(buf, adigit);
		buf += strlen(adigit);
	}
}

char *onedigit(int pos, int digit)
{
	const char *one  = "IXCM";
	const char *five = "VLD";

	char *bp;
	static char buf[128];

	bp = buf;

	if (digit==4) {
		*bp++ = one[pos];
		*bp++ = five[pos];
	}
	else if (digit==9) {
		*bp++ = one[pos];
		*bp++ = one[pos+1];
	}
	else {
		if (digit >= 5) {
			*bp++ = five[pos];
			digit -= 5;
		}
		while (digit--)
			*bp++ = one[pos];
	}

	*bp = '\0';			/* cork off string */
	return buf;
}

static func_info fi(set_current_mode, "roman", "roman numeral mode", roman_output);
