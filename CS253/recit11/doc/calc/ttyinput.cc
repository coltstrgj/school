#include "calc.h"

int peekch()
{
	int c;

	c = readch();
	unreadch(c);
	return c;
}

char erase_ch, kill_ch;
char intr_char=3, quit_char=28, eof_char=4;

static int pending_char = -1;

int readch()
{
	int c;

	if (pending_char != -1) {
		c = pending_char;
		pending_char = -1;
	} else {
		refresh();
		c = getchar();
		/* c = getch(); */
	}

	/* Map all chaotic characters to EOF */
	if (c==intr_char || c==quit_char || c==eof_char)	
		c = EOF;

	return c;
}

void unreadch(char c)
{
	if (pending_char != -1)
		errmsg("Trying to unreadch(%d) but %d is already there.",
			c, pending_char);
	pending_char = c;
}
