#include <sys/types.h>
#include <sys/stat.h>
#include "calc.h"

extern int number_base;
extern int precision;
extern bool print_zeros;
extern Register registers[];

extern long data_time;		/* when .calc was written */

void read_rc(const char *fname)
{
	int i;
	struct stat statbuf;
	FILE *f = fopen(fname, "r");
	if (f==NULL)
		return;
	for (i=0; i<stack_max; i++)
		fscanf(f, "%lg\n", &stack[i]);
	fscanf(f, "%d\n%d\n%d\n%d\n",
		&stack_size, &number_base, &precision, &i);
	print_zeros = i;			// Can't read a bool?
	for (i=0; i<NUM_REG; i++) {
		char name[256];
		number value;
		if (fscanf(f, "%s\n%lg\n", name, &value) == 2) {
			registers[i].name = name;
			registers[i].value = value;
		}
	}
	
	fclose(f);
	stat(fname, &statbuf);
	data_time = statbuf.st_mtime;
}

void write_rc(const char *fname)
{
	FILE *f = fopen(fname, "w");
	if (f==NULL)
		return;
	for (int i=0; i<stack_max; i++)
		fprintf(f, "%.20g\n", stack[i]);
	fprintf(f, "%d\n%d\n%d\n%d\n",
		stack_size, number_base, precision, print_zeros);
	for (int i=0; i<NUM_REG; i++)
		if (registers[i].name != "")
			fprintf(f, "%s\n%.20g\n",
				registers[i].name.c_str(), registers[i].value);
	fclose(f);
}
