#include "calc.h"
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

extern char erase_ch, kill_ch;

static void process(char *buf, char c);

static int base_digit(char c, int base)
{
	const char ok[] = "0123456789abcdefghijklmnopqrstuvwxyz";

	if (isupper(c))
		c = tolower(c);
	const char *p = strchr(ok, c);	/* find the digit */
	if (p==NULL)			/* not there? */
		return -1;
	const int n = p-ok;		/* translate to a number */
	if (n>=base)			/* too big? */
		return -1;
	return n;			/* return number */
}


int getbase(int base)
{
	char buf[256], *p;
	int n, c;

	buf[0] = '\0';

	while ((c=readch()) != EOF) {
		if (eol_char(c))		/* end-of-line? */
			break;			/* fine */

		if (!(base_digit(c, base)!=-1
		|| c==erase_ch || c==kill_ch)) {
			unreadch(c);		/* reject it */
			break;
		}
		process(buf, c);		/* add the character */
	}

	for (n=0, p=buf; *p; p++) {
		n *= base;
		n += base_digit(*p, base);
		if (base_digit(*p, base) == -1)
			errmsg("got -1 from base_digit on '%s'", buf);
	}

	return n;
}
	
number getfloat()
{
	char buf[256], prev;
	int c;

	buf[0] = '\0';

	while ((c=readch()) != EOF) {
		if (buf[0]=='\0')
			prev='\0';
		else
			prev=buf[strlen(buf)-1];
		if (isupper(prev))
			prev = tolower(prev);

		if (eol_char(c))	/* end-of-line? */
			break;		/* fine */

		if (!(isdigit(c) || c=='.'
		|| ((c=='+' || c=='-') && prev=='e')
		|| ((c=='e' || c=='E') && (isdigit(prev) || prev=='.'))
		|| c==erase_ch || c==kill_ch)) {
			unreadch(c);		/* reject it */
			break;
		}
		process(buf, c);		/* add the character */
	}

	return atof(buf);
}
	

int getint()
{
	return getbase(10);
}



void get_str(char *buf)
{
	int c;

	buf[0] = '\0';

	while ((c=readch()) != EOF) {
		if (eol_char(c))	/* end-of-line? */
			break;		/* fine */
		process(buf, c);
	}
}



static void process(char *buf, char c)
{
	int len = strlen(buf);

	if (c==erase_ch) {
		if (len>0) {
			buf[--len] = '\0';
			printw("\b \b");
		}
	}
	
	else if (c==kill_ch) {
		while (len>0) {
			buf[--len] = '\0';
			printw("\b \b");
		}
	}

	else {
		buf[len++] = c;
		buf[len] = '\0';
		printw("%c", c);
	}
}

const char *print_base(int base)
{
	static char buf[40];

	switch(base) {
	case 2:			return "binary";
	case 8:			return "octal";
	case 10:		return "decimal";
	case 16:		return "hex";
	case BASE_ASCII:	return "ascii";
	case BASE_UNIX_TIME:	return "time";
	case BASE_SPLIT_OCTAL:	return "split octal";
	case BASE_SPLIT_HEX:	return "split hex";
	case BASE_UNSIGNED:	return "unsigned decimal";
	case BASE_ROMAN:	return "roman";
	}

	if (base>0)
		sprintf(buf, "%d", base);
	else
		sprintf(buf, "unknown base %d", base);

	return buf;
}


const char *visible(const char *s)
{
	static char buf[128];

	for (buf[0]='\0'; *s; s++) {
		char cbuf[10];
		strcpy(cbuf, unctrl(*s));
		strcat(buf, cbuf);
	}
	return buf;
}
