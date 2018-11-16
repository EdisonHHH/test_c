#include<stdio.h>
#include<string.h>
#include<sys/shm.h>
#include"shmdata.h"
int main()
{
	int shmid=0;
	void *shm=NULL;
	struct sharedType *shared=NULL;
	shmid=shmget((key_t)1234,sizeof(struct sharedType),0666|IPC_CREAT);
	shm=shmat(shmid,(void*)0,0);
	shared=(struct sharedType*)shm;
	while(1){
		if(shared->flag){
			printf("%s",shared->data);
			shared->flag=0;
			if(strncmp(shared->data,"end",3)==0){
				break;
			}
		}
	}
	shmdt(shm);
	shmctl(shmid,IPC_RMID,0);
	return 0;
}
