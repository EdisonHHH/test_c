#ifndef _INTERFACE_H
#define _INTERFACE_H


typedef struct interface {
	char *name;
	void (*fun1)();
	void (*fun2)();
}interface, *p_interface;

#endif