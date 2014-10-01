#include <curses.h>

/* LINTLIBRARY */

extern char erase_ch, kill_ch;


void init_screen()
{
	initscr();
	savetty();
	nonl();
	cbreak();
	noecho();
	clear();
	idlok(stdscr, 1);
	typeahead(0);
	keypad(stdscr, TRUE);

	erase_ch = erasechar();
	kill_ch = killchar();
}


void terminate_screen()
{
	refresh();
	resetty();
	resetterm();
}


void blank(int y, int start, int end)
{
	for (; start<end; start++)
		mvaddch(y, start, ' ');
}


void go(int y, int x)
{
	move(y,x);
}
