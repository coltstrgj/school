#include "calc.h"

extern bool quitting_time;

/* Can't do "stop", because it interferes with "sto" for store-into-register. */
int quit()
{
	quitting_time = true;
	return SUCCESS;
}

static func_info fi1(quit, "quit", "exit calculator");
static func_info fi2(quit, "exit", "exit calculator");
static func_info fi3(quit, "\003", "exit calculator");
static func_info fi4(quit, "\004", "exit calculator");
