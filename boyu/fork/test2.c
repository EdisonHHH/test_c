#include<unistd.h>
#include<stdio.h>
int main()
{
	int i=0;
	printf("test!!");
	for(i=0;i<3;i++){
		pid_t fpid=fork();
		if(fpid==0){
			printf("son %d\n",getpid());
		}
		else{
			printf("father %d\n",getpid());
		}
	}
while(1);
	return 0;
}
