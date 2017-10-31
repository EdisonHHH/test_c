#include<stdio.h>
#include <stdlib.h>
#include<string.h>
#include <sys/time.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <signal.h>
FILE *fp;
int value;
int cur;
void set_flag(int i)
{
	
	value++;
	cur++;
	fseek(fp, 0, SEEK_SET);
	fwrite(&value, sizeof(int), 1, fp);/*将6个浮点数写入文件中*/
	//printf("time up\n");
}
int main()
{
	int i,j;
	struct itimerval tick;
    
    signal(SIGALRM, set_flag);
    memset(&tick, 0, sizeof(tick));
	if((fp=fopen("test","r+b"))==NULL)
		fp=fopen("test","w+b");
			
	fseek(fp, 0, SEEK_SET);
	if(fread(&value, sizeof(int), 1, fp)<1)
			printf("test\n");	
	printf("%d\n",value);
    //Timeout to run first time
    tick.it_value.tv_sec = 1;
    tick.it_value.tv_usec = 0;

    //After first, the Interval time for clock
    tick.it_interval.tv_sec = 1;
    tick.it_interval.tv_usec = 0;       //100ms

    if(setitimer(ITIMER_REAL, &tick, NULL) < 0)
            printf("Set timer failed!\n");
	while(1)
	{
		
	printf("%d,%d\n",cur,value);
sleep(1);
	
	}
	fclose(fp);
	return 0;
}