#include "calc.h"
#include <stdarg.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

const char *pname;
extern Register registers[];

void calculate();
void display_update();
void store_last_x(number x);
const fn_info *current_mode;

int main(int argc, char **argv)
{
	char rc_name[128];

	const char *home = getenv("HOME");
	if (home==NULL)
		home=".";
	sprintf(rc_name, "%s/.calc", home);

	pname = *argv++;		/* Get program name */
	argc--, argv++;

	if (argc>=2 && strcmp(*argv, "-f")==0) {
		argv++, argc--;		/* skip -f */
		strncpy(rc_name, *argv, sizeof(rc_name));
		rc_name[sizeof(rc_name)-1] = '\0';
		argv++, argc--;		/* skip filename */
	}

	set_default_status();
	read_rc(rc_name);
	init_screen();
	calculate();
	terminate_screen();
	write_rc(rc_name);

	return(0);
}

long data_time = 0;		/* when .calc was written */
bool quitting_time = false;

fn_info *current_cmd;

void calculate()
{
	// Set the output mode to decimal.
	for (const fn_info *p=functions; p->fn_ptr; p++)
		if (p->key == "dec")
			current_mode = p;

	while (!quitting_time) {
		number num;

		display_update();
		if (data_time!=0)
			msg("Restoring data from %.24s", ctime(&data_time));
		data_time=0;

		int i = get_command(&num, &current_cmd);
		switch (i) {
		case GET_COMMAND_EOF:
			addch('\n');
			clrtoeol();
			return;

		case GET_COMMAND_NUM:		/* a number */
			store_last_x(push(pop()));
			push(num);
			break;

		case GET_COMMAND_FUN:		/* a function */
			gotoxy(0, 1);
			clrtobot();
			number last_x = push(pop());
			i = (*current_cmd->fn_ptr)();
			if (i!=SUCCESS && i!=FAILURE)
				errmsg("Error: function returns %d?", i);
			store_last_x(last_x);
		}
	}
}


int number_base;
int precision;
bool print_zeros;

void set_default_status()
{
	clear_stack();

	for (int i=0; i<NUM_REG; i++)
		registers[i].name = "";	/* invalid register */

	stack_size = 8;
	number_base = 10;
	precision = 15;
	print_zeros = false;
}



extern int LINES;

void display_update()
{
	erase();

	gotoxy(0, LINES-1);
	printw("base: %s  precision: %d", print_base(number_base), precision);

	/* Display the stack */
	for (int i=0; i<stack_size; i++) {
		gotoxy(0, i+2);
		printw("%2d: ", i);
		print_number(stack[i]);
	}

	/* Display the registers */
	int reg_loc = 2;
	for (int i=0; i<NUM_REG && reg_loc<=LINES-2; i++) {
		if (registers[i].name != "") {
			gotoxy(40, reg_loc++);
			printw("%10.10s: ", registers[i].name.c_str());
			print_number(registers[i].value);
		}
	}
}


/* VARARGS1 */
void msg(const char *fmt, ...)
{
	va_list ap;
	va_start(ap, fmt);

	gotoxy(0, 0);
	clrtoeol();
	vw_printw(stdscr, fmt, ap);
	va_end(ap);
	refresh();
}

/* VARARGS1 */
void errmsg(const char *fmt, ...)
{
	va_list ap;
	va_start(ap, fmt);

	gotoxy(0,0);
	clrtoeol();
	standout();
	vw_printw(stdscr, fmt, ap);
	va_end(ap);
	standend();
	refresh();
}

void gotoxy(int x, int y)
{
	move(LINES-1-y, x);
}

void print_number(number n)
{
	int width=26;
	const char *p = number_to_string(n, width);

	printw("%*.*s", width, width, p);
}



void store_last_x(number x)
{
	if (store("lastx", x) == FAILURE)
		msg("Can't save last x");
}

int set_current_mode()
{
	current_mode = current_cmd;
	return SUCCESS;		/* This can be somebody's function */
}
