/*
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<errno.h>
#include<sys/types.h>
#include<stropts.h>
#include<sys/poll.h>
#include<sys/stropts.h>
#include<string.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<poll.h>
#define BUFSIZE 1024
int main(int argc,char *argv[])
{
	char buf[BUFSIZE];
	int bytes;
	struct pollfd *pollfd;
	int i=0;
	int nummonitor=0;
	int numready;
	int errno;
	char *str;
	if(argc!=3)
	{
		fprintf(stderr,"Usage:the argc num error\n");
		exit(1);
	}
	if((pollfd=(struct pollfd*)calloc(2,sizeof(struct pollfd)))==NULL)
		exit(1);
	for(i;i<2;i++)
	{
		str=(char*)malloc(20*sizeof(char));
		memcpy(str,"/home/user/pro/",20);
		strcat(str,argv[i+1]);
		printf("str=%s\n",str);
		(pollfd+i)->fd=open(str,O_RDONLY);
		if((pollfd+i)->fd>=0)
			fprintf(stderr,"open(pollfd+%d)->fd:%s\n",i,argv[i+1]);
		nummonitor++;
		(pollfd+i)->events=POLLIN;
	}
	printf("nummonitor=%d\n",nummonitor);
	while(nummonitor>0)
	{
		numready=poll(pollfd,2,-1);
		if(numready==-1&&errno==EINTR)
			continue;
		else if(numready==-1)
			break;
		printf("numready=%d\n",numready);

		for(i=0;nummonitor>0&&numready>0;i++)
		{
			if((pollfd+i)->revents&POLLIN)
			{
				bytes=read(pollfd[i].fd,buf,BUFSIZE);
				numready--;
				printf("pollfd[%d]->fd read buf:\n%s \n",i,buf);
				nummonitor--;
			}
		}
	}
	for(i=0;i<nummonitor;i++)
		close(pollfd[i].fd);
	free(pollfd);
	return 0;
}
*/


/*
#include<sys/types.h>
#include<sys/stat.h>
#include<stdio.h>
#include<fcntl.h>
#include<signal.h>
#include<unistd.h>
#define MAX_LEN 100
void input_handler(int num)
{
	char data[MAX_LEN];
	int len;

	len=read(STDIN_FILENO,&data,MAX_LEN);
	data[len]=0;
	printf("input available:%s\n",data);
}

int main()
{
	int oflags;

	signal(SIGIO,input_handler);
	fcntl(STDIN_FILENO,F_SETOWN,getpid());
	oflags=fcntl(STDIN_FILENO,F_GETFL);
	fcntl(STDIN_FILENO,F_SETFL,oflags|FASYNC);

	while(1);
}
*/


/*
#include<stdio.h>

#define offsetof(TYPE,MEMBER) ((size_t)&((TYPE*)0)->MEMBER)

#define container_of(ptr,type,member) ({const typeof(((type*)0)->member) *__mptr=(ptr);\
										(type*)((char*)__mptr-offsetof(type,member));})

struct test_struct
{
	int num;
	char ch;
	float f1;
};
int main(void)
{
	struct test_struct *test;
	struct test_struct init={12,'a',12.3};
	float *ptr_f=&init.f1;
	test=container_of(ptr_f,struct test_struct,f1);
	printf("test->num=%d\n",test->num);
	printf("test->ch=%c\n",test->ch);
	printf("test->f1=%f\n",test->f1);


	int a=6,b=2;
	int c=({a+b;a-b;});
	printf("%d\n",c);

	printf("%d,%d,%d\n",offsetof(struct test_struct,num),offsetof(struct test_struct,ch),offsetof(struct test_struct,f1));
	return 0;
}
*/
/*
#include<stdio.h>
#include<malloc.h>
struct var_data
{
	int len;
	int data[0];
};
int main()
{
	int a=10;
	int i;
	struct var_data *p=(struct var_data*)malloc(sizeof(struct var_data)+sizeof(int)*a);
	p->len=a;
	for(i=0;i<p->len;i++)
		p->data[i]=i;
	for(i=0;i<p->len;i++)
		printf("%d ",p->data[i]);
	printf("\n");
	return 0;
}
*/


/*
#include<stdio.h>
#include<pthread.h>
pthread_mutex_t mutex;
pthread_cond_t cond;
void *fun_thread(void *arg)
{
	while(1)
	{
		sleep(10);
		pthread_mutex_lock(&mutex);
		pthread_cond_signal(&cond);
		pthread_mutex_unlock(&mutex);
	}
}

int main()
{
	int i;
	pthread_t fd;
	pthread_create(&fd,NULL,fun_thread,NULL);
	pthread_mutex_init(&mutex,NULL);
	pthread_cond_init(&cond,NULL);
	while(1)
	{
		pthread_mutex_lock(&mutex);
		pthread_cond_wait(&cond,&mutex);
		printf("process...\n");
		pthread_mutex_unlock(&mutex);
	}
	return 0;
}
*/

#include<stdio.h>
int main()
{
	int buf[4];
	printf("%d\n",sizeof(buf));
	return 0;
}
