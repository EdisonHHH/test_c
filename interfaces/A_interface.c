#include<stdio.h>
#include"interface.h"
void A_interface_fun1()
{
	printf("A_fun1\n");
}
void A_interface_fun2()
{
	printf("A_fun2\n");
}
struct interface A_interface = {
	.name    = "A",
	.fun1    = A_interface_fun1,
	.fun2    = A_interface_fun2,
};


void A_interface_add(void)
{
	register_interface(&A_interface);
}
