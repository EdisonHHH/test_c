#include "interface.h"

#define INTERFACE_NUM 10

static p_interface p_array_interface[INTERFACE_NUM];
static p_interface g_p_interface_selected;

int register_interface(p_interface pinter)
{
	int i;
	for (i = 0; i < INTERFACE_NUM; i++)
	{
		if (!p_array_interface[i])
		{
			p_array_interface[i] = pinter;
			return i;
		}
	}
	return -1;		
}

int select_interface(char *name)
{
	int i;
	for (i = 0; i < INTERFACE_NUM; i++)
	{
		if (p_array_interface[i] && !strcmp(p_array_interface[i]->name, name))
		{
			g_p_interface_selected = p_array_interface[i];
			return i;
		}
	}
	return -1;		
}




void interface_fun1(void)
{
	if (g_p_interface_selected)
	{
		g_p_interface_selected->fun1();
	}
}

void interface_fun2(void)
{
	if (g_p_interface_selected)
	{
		g_p_interface_selected->fun2();
	}
}


void interface_add(void)
{
	A_interface_add();
	B_interface_add();
}
