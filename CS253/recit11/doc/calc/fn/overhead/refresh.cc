#include "calc.h"

int repaint_screen()
{
	clearok(stdscr, 1);
	refresh();
	return SUCCESS;
}

static func_info fi(repaint_screen, "\f", "repaint screen");
