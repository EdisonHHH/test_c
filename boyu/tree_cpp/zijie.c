#include <stdio.h>


int main()
{
	union{
		int a;
		char b;
	}c;

	c.a = 1;

	if(c.b)
		printf("little endian\n");
	else
		printf("big endian\n");

	return 0;
}
