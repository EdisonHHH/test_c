#include<stdio.h>
#include<malloc.h>
void heap(int *a,int n,int i)
{
	int child;
	int tmp=a[i];
	for(;2*i+1<n;i=child)
	{
		child=2*i+1;
		if(child+1<n&&a[child]<a[child+1])
			child++;
		if(tmp<a[child])
			a[i]=a[child];
		else
			break;
	}
	a[i]=tmp;
}
void get_small_k_of_n(int *a,int n,int k)
{
	int *b=(int*)malloc(sizeof(int)*k);
	for(int i=0;i<k;i++)
		b[i]=a[i];
	for(int i=k/2-1;i>=0;i--)
		heap(b,k,i);
		
	for(int i=k;i<n;i++)
	{
		if(a[i]<b[0])
		{
		b[0]=a[i];
		heap(b,k,0);
		}
	}
	
	for(int i=k-1;i>0;i--)
	{
		b[i]^=b[0];
		b[0]^=b[i];
		b[i]^=b[0];
		heap(b,i,0);
	}
	for(int i=0;i<k;i++)
		printf("%d ",b[i]);
	printf("\n");
	free(b);
}
#include<stdlib.h>
#define N 10000000
#define random(i) (rand()%i)
int a[N];
int flag[N];
int main()
{
	int num=0;
	printf("get random %d start\n",N);
	while(num<N)
	{
		int buf=random(N);
		if(flag[buf]==0)
		{
			flag[buf]=1;
			a[num++]=buf;
		}
	}
	printf("get random %d end\n",N);
	int k;
	while(scanf("%d",&k)!=EOF)
	{
		get_small_k_of_n(a,N,k);
	}
	return 0;
}