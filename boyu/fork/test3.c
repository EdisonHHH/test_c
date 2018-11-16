#include<unistd.h>
#include<stdio.h>
int main()
{
	fork();
	fork()&&fork()||fork();
	fork();
	printf("+\n");
	while(1);
	return 0;
}
