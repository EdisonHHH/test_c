#include<stdio.h>
#include<stdlib.h>
#define N 100
#define random(i) (rand()%i)
int a[N];
int flag[N];
void fun(int *a,int n)
{
	int i=0,j=0,k=0;
	int buf=0;
	if(a==NULL||n<=0){
		return;
	}
	while(i<n&&j<n)
	{
		if(a[i]%2==0)
		{ 
			j=i;
			while(j<n&&a[j]%2==0)
			{
				j++;
			}
			if(j<n)
			{
				buf=a[j];
				for(k=j;k>i;k--)
				{
					a[k]=a[k-1];
				}	
				a[i]=buf;
			}
		}
		i++;
	}
}
int main()
{
	int i;
	int num=0;
	while(num<N)
	{
		int buf=random(N);
		if(flag[buf]==0)
		{
			flag[buf]=1;
			a[num++]=buf;
		}
	}
	for(i=0;i<N;i++){
		printf("%d ",a[i]);	
	}
	printf("\n");
	
	fun(a,N);
	for(i=0;i<N;i++){
		printf("%d ",a[i]);	
	}
	printf("\n");
	return 0;
}
