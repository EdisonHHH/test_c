#include<stdio.h>
#include<string.h>
#include<sys/msg.h>
#include<sys/ipc.h>
#include<sys/types.h>
#include<sys/stat.h>
#include"msgdata.h"
#define PERM S_IRUSR|S_IWUSR
#define MSG_FILE "msgserver.c"
int main(int argc,char **argv)
{
	struct msgtype msg;
	int msgid=0;
	key_t key;
	key=ftok(MSG_FILE,'a');
	msgid=msgget(key,0666|IPC_CREAT);
	if(msgid==-1)
	{
		printf("test wrong\n");
	}
	msg.mtype=1;
	strncpy(msg.buffer,argv[1],100);
	msgsnd(msgid,&msg,sizeof(struct msgtype)-sizeof(long),0);
	memset(&msg,'\0',sizeof(struct msgtype));
	msgrcv(msgid,&msg,sizeof(struct msgtype)-sizeof(long),2,0);
	printf("Client Receive:%s\n",msg.buffer);
		
	return 0;
}
