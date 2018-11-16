#include<unistd.h>
#include<stdio.h>

#include<stdlib.h>


#include<unistd.h>
int main()
{
	pid_t fpid;
	int count=0;
	printf("start\n");
	fpid=fork();
	if(fpid<0){
		printf("error in fork");	
	}
	else if(fpid==0){
		printf("i am the child process,my process id is %d\n",getpid());	
		count++;	
	}
	else{
		printf("i am the parent process,my process id is %d,the child process id is %d\n",getpid(),fpid);
		count++;
	}
	printf("total number is %d\n",count);
	exit(0);
}
