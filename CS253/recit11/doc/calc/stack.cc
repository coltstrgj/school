#include "calc.h"

int stack_max=STACK_MAX;
number stack[STACK_MAX];
int stack_size;


number push(number num)
{
	for (int i=stack_size-1; i>0; i--)
		stack[i] = stack[i-1];
	stack[0] = num;
	return num;
}

number pop()
{
	number num = stack[0];

	for (int i=0; i<stack_size-1; i++)
		stack[i] = stack[i+1];

	return num;
}

void clear_stack()
{
	for (int i=0; i<stack_max; i++)
		stack[i]=0;
}
