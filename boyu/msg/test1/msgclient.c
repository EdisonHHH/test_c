#include<stdio.h>
#include<string.h>
#include<sys/msg.h>
#include<sys/ipc.h>
#include<sys/types.h>
#include<sys/stat.h>
#include"msgdata.h"
int main()
{
	int msgid;
	struct msgType msg;
	int msg_size=sizeof(struct msgType)-sizeof(long);
	msgid=msgget((key_t)1234,0666|IPC_CREAT);
	while(1){
		printf("please enter a test:");
		fgets(msg.data,msg_size,stdin);
		msg.Type=1;
		msgsnd(msgid,&msg,msg_size,0);
		if(strncmp(msg.data,"end",3)==0){
					break;
				}
		msgrcv(msgid,&msg,msg_size,2,0);
		printf("Client receive:%s",msg.data);
	}
	return 0;
}
