#include<pthread.h>
#include<stdio.h>
struct Tsk_hndl;
typedef void (*Fun)(struct Tsk_hndl *pTsk); 
typedef struct Tsk_hndl{
	int num;
	pthread_t hndl;
	Fun fun;
} Tsk_hndl; 
typedef struct{
	Tsk_hndl Tsk1;
	Tsk_hndl Tsk2;
	Tsk_hndl Tsk3;
} Tsks_type;
Tsks_type Tsks;
void *thread_main(void *pPrm)
{
	Tsk_hndl *pPrc=(Tsk_hndl*)pPrm;
	pPrc->fun(pPrc);
}

void Tsk1_fun(struct Tsk_hndl *pTsk)
{
	while(1){
		printf("%d:Tsk1\n",pTsk->num);
		sleep(3);
	}
}

void Tsk2_fun(struct Tsk_hndl *pTsk)
{
	while(1){
		printf("%d:Tsk2\n",pTsk->num);
		sleep(3);
	}
}

void Tsk3_fun(struct Tsk_hndl *pTsk)
{
	while(1){
		printf("%d:Tsk3\n",pTsk->num);
		sleep(3);
	}
}

void tsk_create(Tsk_hndl *pTsk,Fun fun,int i)
{
	pTsk->num=i;
	pTsk->fun=fun;
	pthread_create(&pTsk->hndl,NULL,thread_main,pTsk);
	
}
int main()
{
	tsk_create(&Tsks.Tsk1,Tsk1_fun,1);
	sleep(1);
	tsk_create(&Tsks.Tsk2,Tsk2_fun,2);
	sleep(1);
	tsk_create(&Tsks.Tsk3,Tsk3_fun,3);
	pthread_join(Tsks.Tsk1.hndl,NULL);
	pthread_join(Tsks.Tsk2.hndl,NULL);
	pthread_join(Tsks.Tsk3.hndl,NULL);
	return 0;
}
