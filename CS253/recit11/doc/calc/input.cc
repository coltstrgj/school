#include "calc.h"
#include <ctype.h>
#include <sys/types.h>
#include <string.h>

extern int number_base;
extern char erase_ch, kill_ch;

static char ctrl(char letter) {
	return letter & 037;
}

/*
 * Get a command from the user
 */
int get_command(number *num, fn_info **fn_ptr)
{
	static fn_info *last_command = NULL;
	char cmd[80];
	const char prompt[] ="Command: ";

	gotoxy(0, 1);
	printw(prompt);
	clrtoeol();

	cmd[0] = '\0';
	for (char *cp=cmd; ;) {
		gotoxy(strlen(prompt)+strlen(cmd), 1);
		int c = readch();
		if (c==EOF)
			return GET_COMMAND_EOF;

		/* redo? */
		if (cp==cmd && c==ctrl('r') && last_command != NULL) {
			*fn_ptr = last_command;
			return GET_COMMAND_FUN;
		}

		/* input of non-decimal */
		if (cp==cmd && isdigit(c) && number_base!=10) {
			unreadch(c);
			*num = getbase(number_base);
			return GET_COMMAND_NUM;
		}

		if (cp==cmd && (c=='.' || isdigit(c)) && number_base==10) {
			unreadch(c);
			*num = getfloat();
			return GET_COMMAND_NUM;
		}

		/* Erase character? */
		if (c==erase_ch) {
			if (cp>cmd) {
				*--cp = '\0';	 /* erase the character */
				printw("\b \b"); /* erase it visually */
			}
			continue;
		}
		/* Kill character? */
		if (c==kill_ch) {
			while (cp>cmd) {
				*--cp = '\0';
				printw("\b \b");
			}
			continue;
		}

		if (eol_char(c))		/* various types of enter */
			c=' ';			/* all map to this one */
		if (c!=' ')			/* if not the enter delimiter */
			*cp++ = c;		/* add it to the command */
		*cp = '\0';

		/* Try to find this command */
		int possibilities=0;
		for (fn_info *p=functions; p->fn_ptr; p++) {
			const char *fun = cmd;
			if (*fun == '\0')		/* a null command */
				fun = "enter";		/* maps to this one */

			/*
			 * Try for a complete match only if he hit enter/space
			 * or if it's a one-letter command.
			 */
			if ((c==' ' || p->key.length()==1) && p->key == fun) {
				addch(c);
				msg("Last command: %s", visible(fun));
				addch('\r');		/* start of line */
				refresh();
				last_command = *fn_ptr = p;
				return GET_COMMAND_FUN;
			}
			/* Try for a possible match */
			if (strncmp(p->key.c_str(), fun, strlen(fun))==0)
				possibilities++;
		}
		if (c==' ') {
			errmsg("\"%s\" is not a command", visible(cmd));
		}
		else if (possibilities==0) {
			errmsg("No command starts with \"%s\"", visible(cmd));
			*--cp = '\0';		/* Eliminate it */
		}
		else
			addch(c);		/* Good so far. */
	}
}
