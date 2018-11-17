#include<stdio.h>
#include"interface.h"
void B_interface_fun1()
{
	printf("B_fun1\n");
}
void B_interface_fun2()
{
	printf("B_fun2\n");
}
struct interface B_interface = {
	.name    = "B",
	.fun1    = B_interface_fun1,
	.fun2    = B_interface_fun2,
};


void B_interface_add(void)
{
	register_interface(&B_interface);
}
