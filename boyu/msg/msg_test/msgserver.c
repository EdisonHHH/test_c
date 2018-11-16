#include<stdio.h>
#include<string.h>
#include<sys/msg.h>
#include<sys/ipc.h>
#include<sys/types.h>
#include<sys/stat.h>
#include"msgdata.h"
#define PERM S_IRUSR|S_IWUSR
#define MSG_FILE "msgserver.c"
int main()
{
	struct msgtype msg;
	int msgid=0;
	key_t key;
	key=ftok(MSG_FILE,'a');
	msgid=msgget(key,0666|IPC_CREAT);
	if(msgid==-1)
	{
		printf("test wrong\n");
		return -1;
	}
	while(1){
		msgrcv(msgid,&msg,sizeof(struct msgtype)-sizeof(long),1,0);
		printf("Server Receive:%s\n",msg.buffer);
		msg.mtype=2;
		msgsnd(msgid,&msg,sizeof(struct msgtype)-sizeof(long),0);
		if(strncmp(msg.buffer,"end",3)==0){
			break;		
		}
	}
	sleep(1);
	msgctl(msgid, IPC_RMID, 0);
	return 0;
}
