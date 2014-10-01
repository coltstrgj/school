#include <stdio.h>
#include <curses.h>
#include <math.h>
#include <string>

using namespace std;

typedef double number;

/* Results of get_command() */
enum {
	GET_COMMAND_EOF=1,
	GET_COMMAND_NUM=2,
	GET_COMMAND_FUN=3,
};

/* Function results */
enum {
	SUCCESS=1,
	FAILURE=0,
};

/* Special output bases */
/* Positive numbers indicate corresponding base */
enum {
	BASE_ASCII	 = -1,		/* ASCII characters */
	BASE_UNIX_TIME	 = -2,		/* as per ctime(3) */
	BASE_SPLIT_OCTAL = -3,		/* octal per byte with spaces */
	BASE_SPLIT_HEX	 = -4,		/* hex with spaces */
	BASE_UNSIGNED	 = -5,		/* unsigned decimal */
	BASE_ROMAN	 = -6,		/* roman numerals */
	BASE_WORDS	 = -7,		/* one, two, three, etc. */
};

typedef int (fn)();

struct fn_info {
	fn *fn_ptr;
	string key;
	string description;
	char *(*input)();
	const char *(*output)(int number_base, number num, int width);
};

extern fn_info *functions;
extern const fn_info *current_mode;

#include "func_info.h"
#include "stack.h"

#define eol_char(c) ((c)==' ' || (c)=='\t' || (c)=='\r' || (c)=='\n')

extern int set_current_mode();

void msg(const char *fmt, ...);
void errmsg(const char *fmt, ...);
void set_default_status();

void read_rc(const char *fname);
void write_rc(const char *fname);

void init_screen();
void terminate_screen();
void blank(int y, int start, int end);
void go(int y, int x);

int get_command(number *num, fn_info **fn_ptr);
void gotoxy(int x, int y);
void print_number(number n);

int store(const char *name, number value);
int recall(const char *name, number *value);
int delete_reg(const char *name);
Register *find_reg(const char *name);

int peekch();
int readch();
void unreadch(char c);

int getbase(int base);
number getfloat();
int getint();
void get_str(char *buf);
const char *print_base(int base);
const char *visible(const char *s);
const char *number_to_string(number num, int width);
