/*
#include<pthread.h>
#include<stdio.h>
pthread_mutex_t mutex;
void *print_msg(void *arg)
{
	int i=0;
	pthread_mutex_lock(&mutex);
	for(i=0;i<10;i++){
		printf("%d:%d\n",*(int*)arg,i);	
	}
	pthread_mutex_unlock(&mutex);
}
int main()
{
	pthread_t id1,id2;
	int i=1;
	int j=2;
	pthread_mutex_init(&mutex,NULL);
	pthread_create(&id1,NULL,print_msg,&i);
	pthread_create(&id2,NULL,print_msg,&j);
	pthread_join(id1,NULL);
	pthread_join(id2,NULL);
	pthread_cancel(id1);
	pthread_cancel(id2);
	pthread_mutex_destroy(&mutex);
	return 0;
}
*/
/*
#include<pthread.h>
#include<stdio.h>
pthread_mutex_t mutex;
pthread_cond_t  cond;
int flag=0;
void *print_msg(void *arg)
{
	int i;
	while(1)
	{
		pthread_mutex_lock(&mutex);

		pthread_cond_wait(&cond, &mutex);
	
		for(i=0;i<10;i++)
		{
			printf("%d:%d\n",*(int*)arg,i);
		}

		pthread_mutex_unlock(&mutex);
	}
}
int main()
{
	pthread_t f1;
	int i=1;
	int count=0;
	pthread_mutex_init(&mutex,NULL);
	pthread_cond_init(&cond, NULL); 
	pthread_create(&f1,NULL,print_msg,&i);
	while(1)
	{
		sleep(10);
		pthread_mutex_lock(&mutex);
		printf("enable print msg  %d\n",count++);
		pthread_cond_signal(&cond);

		pthread_mutex_unlock(&mutex);
	}
	//pthread_join(f1,NULL);
	pthread_cancel(f1);
	pthread_mutex_destroy(&mutex);
	return 0;
}
*/
#include<pthread.h>
#include<stdio.h>
#include <termios.h>
#include <unistd.h>
#include <stdio.h>
pthread_mutex_t mutex;
pthread_cond_t  cond;
int flag=0;
void *print_msg(void *arg)
{
	
	int count=0;
	char c;

 	struct termios tTTYState;
    //get the terminal state
    tcgetattr(STDIN_FILENO, &tTTYState);
    //turn off canonical mode
    tTTYState.c_lflag &= ~ICANON;
    //minimum of number input read.
    tTTYState.c_cc[VMIN] = 1;   /* 有一个数据时就立刻返回 */
    //set the terminal attributes.
    tcsetattr(STDIN_FILENO, TCSANOW, &tTTYState);

	while(1)
	{
		c=fgetc(stdin);  /* 会休眠直到有输入 */
		pthread_mutex_lock(&mutex);

		printf("\nenable print msg  %d\n",count++);

		pthread_cond_signal(&cond);
		pthread_mutex_unlock(&mutex);
	}
}
int main()
{
	pthread_t f1;
	int i=1;
	int j;
	pthread_mutex_init(&mutex,NULL);
	pthread_cond_init(&cond, NULL); 
	pthread_create(&f1,NULL,print_msg,&i);
	while(1)
	{
		pthread_mutex_lock(&mutex);
		pthread_cond_wait(&cond, &mutex);
		for(j=0;j<10;j++)
		{
			printf("%d\n",j);
		}
		pthread_mutex_unlock(&mutex);
	}
	//pthread_join(f1,NULL);
	pthread_cancel(f1);
	pthread_mutex_destroy(&mutex);
	return 0;
}
