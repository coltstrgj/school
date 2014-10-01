#include "calc.h"
#include <stdio.h>
#include <string.h>

extern fn repaint_screen;


int help()
{
	char cmd[80];
	int len, maxlen;
	FILE *out;

	strcpy(cmd, "sort | pr -2 -l999 -t | more");

	refresh();			/* Can't trust a fork */
	resetterm();
	out = popen(cmd, "w");
	if (out==NULL) {
		perror(cmd);
		errmsg("Can't open pipe");
		return FAILURE;
	}

	puts("\n\t\t\t*** List of functions ***\n");

	/* Compute maximum length */
	maxlen = 0;
	for (const fn_info *p=functions; p->fn_ptr; p++) {
		len = p->key.length();
		if (len>maxlen)
			maxlen=len;
	}

	/* Print stuff */
	for (const fn_info *p=functions; p->fn_ptr; p++) {
		string key = p->key;
		if (key=="")
			key="<return>";
		else if (key=="\f")
			key="<cntl-L>";
		fprintf(out, "%s:", key.c_str());

		for (len=key.length(); len<maxlen; len++)
			putc(' ', out);
		putc(' ', out);
		fprintf(out, "%s\n", p->description.c_str());
	}

	fflush(out);
	if (pclose(out) == -1) {
		perror(cmd);
		errmsg("Can't close pipe");
		return FAILURE;
	}

	printf("[return] to continue: ");
	readch();
	fixterm();
	repaint_screen();
	return SUCCESS;
}

static func_info fi(help, "help", "help listing");
static func_info fi2(help, "?", "help listing");
