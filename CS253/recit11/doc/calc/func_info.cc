#include "calc.h"

const int MAX_FUNCS=500;
int num_funcs = 0;
fn_info *functions;	// Avoid static initialization fiasco

func_info::func_info(fn *fn_ptr,
		     const char *key,
		     const char *description,
		     const char *(*output)(int base, number num, int width)
		     ) {
	if (!functions)
		functions = new fn_info[MAX_FUNCS];
	fn_info *p = &functions[num_funcs++];
	p->fn_ptr = fn_ptr;
	p->key = key;
	p->description = description;
	p->input = NULL;
	p->output = output;
}
