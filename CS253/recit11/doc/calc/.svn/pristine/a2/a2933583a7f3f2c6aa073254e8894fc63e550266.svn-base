#include "calc.h"

Register registers[NUM_REG];

Register *find_reg(const char *name)
{
	for (Register *p=registers; p<&registers[NUM_REG]; p++)
		if (p->name == name)
			return p;

	return NULL;
}

static number *is_stack(const string &name)
{
	if (name == ".x") return &stack[0];
	if (name == ".y") return &stack[1];
	if (name == ".z") return &stack[2];
	if (name == ".0") return &stack[0];
	if (name == ".1") return &stack[1];
	if (name == ".2") return &stack[2];
	if (name == ".3") return &stack[3];
	if (name == ".4") return &stack[4];
	if (name == ".5") return &stack[5];
	if (name == ".6") return &stack[6];
	if (name == ".7") return &stack[7];
	if (name == ".8") return &stack[8];
	if (name == ".9") return &stack[9];
	return NULL;
}

int store(const char *name, number value)
{
	if (number *stackloc = is_stack(name)) {
		*stackloc = value;
		return SUCCESS;
	}

	Register *p = find_reg(name);	/* find our target */
	if (p==NULL) {
		p = find_reg("");		/* find an empty one */
		if (p==NULL)
			return FAILURE;
		p->name = name;
	}

	p->value = value;
	return SUCCESS;
}

int recall(const char *name, number *value)
{
	if (const number *stackloc = is_stack(name)) {
		*value = *stackloc;
		return SUCCESS;
	}

	Register *p = find_reg(name);
	if (p==NULL)
		return FAILURE;
	*value = p->value;
	return SUCCESS;
}


int delete_reg(const char *name)
{
	Register *p = find_reg(name);
	if (p==NULL)
		return FAILURE;

	p->name = "";
	return SUCCESS;
}
