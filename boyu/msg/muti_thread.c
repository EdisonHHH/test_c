#include <pthread.h>
#include <stdlib.h>
#include <string.h>
#include<stdio.h>
struct TskHndl;
typedef int (*TskFnc)(struct TskHndl *pTsk);

typedef struct TskHndl {
	pthread_t  hndl;    
	TskFnc  fncMain;  
} TskHndl;
typedef struct {
	TskHndl Tsk1;
	TskHndl Tsk2;
	TskHndl Tsk3;
	TskHndl Tsk4;														    
} Tsks_type;
Tsks_type Tsks;
void *ThrMain(void *pPrm)
{
	TskHndl *pPrc;

	pPrc = (TskHndl *)pPrm;
	while(1)
	{
		pPrc->fncMain(pPrc);
	}
}
int tsk1_Thr(struct TskHndl *pTsk)
{
	while(1)
	{
		printf("tsk1\n");
		sleep(5);
	}
	return 0;
}
int tsk1_Create()
{
	int status;
	Tsks.Tsk1.fncMain=tsk1_Thr;
	status=pthread_create(&Tsks.Tsk1.hndl, NULL, ThrMain, &Tsks.Tsk1);
	return status;
}
int tsk1_Delete()
{
	int status;
	status=pthread_cancel(Tsks.Tsk1.hndl);
	Tsks.Tsk1.fncMain=NULL;
	return status;
}
int tsk2_Thr(struct TskHndl *pTsk)
{
	while(1)
	{
		printf("tsk2\n");
		sleep(5);
	}
	return 0;
}
int tsk2_Create()
{
	int status;
	Tsks.Tsk2.fncMain=tsk2_Thr;
	status=pthread_create(&Tsks.Tsk2.hndl,NULL,ThrMain,&Tsks.Tsk2);
	return status;
}
int tsk2_Delete()
{
	int status;
	status=pthread_cancel(Tsks.Tsk2.hndl);
	Tsks.Tsk2.fncMain=NULL;
	return status;
}
int tsk3_Thr(struct TskHndl *pTsk)
{
	while(1)
	{
		printf("tsk3\n");
		sleep(5);
	}
	return 0;
}
int tsk3_Create()
{
	int status;
	Tsks.Tsk3.fncMain=tsk3_Thr;
	status=pthread_create(&Tsks.Tsk3.hndl, NULL, ThrMain, &Tsks.Tsk3);
	return status;
}
int tsk3_Delete()
{
	int status;
	status=pthread_cancel(Tsks.Tsk3.hndl);
	Tsks.Tsk3.fncMain=NULL;
	return status;
}
int tsk4_Thr(struct TskHndl *pTsk)
{
	while(1)
	{
		printf("tsk4\n");
		sleep(5);
	}
	return 0;
}
int tsk4_Create()
{
	int status;
	Tsks.Tsk4.fncMain=tsk4_Thr;
	status=pthread_create(&Tsks.Tsk4.hndl,NULL,ThrMain,&Tsks.Tsk4);
	return status;
}
int tsk4_Delete()
{
	int status;
	status=pthread_cancel(Tsks.Tsk4.hndl);
	Tsks.Tsk4.fncMain=NULL;
	return status;
}
int main()
{
	int err=0;
	err|=tsk1_Create();
	sleep(1);
	err|=tsk2_Create();
	sleep(1);
	err|=tsk3_Create();
	sleep(1);
	err|=tsk4_Create();
	sleep(1);
	if(err!=0)
	{
		printf("Can't create thread\n");
	}
	int count=0;
	while(1)
	{
		printf("hello world!!! from main\n");
		count++;
		if(count>=5)
		{
			break;
		}	
		sleep(5);
	}
	tsk4_Delete();
	tsk3_Delete();
 	tsk2_Delete();
 	tsk1_Delete();
	return 0;
}
