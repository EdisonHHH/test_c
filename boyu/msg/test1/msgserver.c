#include<stdio.h>
#include<string.h>
#include<sys/msg.h>
#include<sys/ipc.h>
#include<sys/types.h>
#include<sys/stat.h>
#include"msgdata.h"
int main()
{
	int msgid=0;
	struct msgType msg;
	msgid=msgget((key_t)1234,0666|IPC_CREAT);
	while(1){
		msgrcv(msgid,&msg,sizeof(struct msgType)-sizeof(long),1,0);
		printf("Server receive:%s",msg.data);
		if(strncmp(msg.data,"end",3)==0){
			break;		
		}
		printf("please enter a test:");
		fgets(msg.data,sizeof(struct msgType)-sizeof(long),stdin);
		msg.Type=2;
		msgsnd(msgid,&msg,sizeof(struct msgType)-sizeof(long),0);	
	}
	msgctl(msgid,IPC_RMID,0);
	return 0;
}
