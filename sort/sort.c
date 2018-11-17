#include<stdio.h>
#include<malloc.h>
void insertSort(int *a,int n)
{
	if(a==NULL||n<=1)
		return;
	int i;
	for(i=1;i<n;i++)
	{
		int j=i-1;
		int x=a[i];
		while(j>=0&&a[j]>x)
		{
			a[j+1]=a[j];
			j--;
		}
		a[j+1]=x;
	}
}
void shell(int *a,int n,int k)
{
	for(int i=1;i<n;i+=k)
	{
		int j=i-k;
		int x=a[i];
		while(j>=0&&a[j]>x)
		{
			a[j+k]=a[j];
			j-=k;
		}
		a[j+k]=x;
	}
}
void shellSort(int *a,int n)
{
	if(a==NULL||n<=1)
		return;
	int k=n/2;
	while(k)
	{
		shell(a,n,k);
		k/=2;
	}
}
void selectSort(int *a,int n)
{
	if(a==NULL||n<=1)
		return;
	for(int i=0;i<n-1;i++)
	{
		int x=i;
		for(int j=i+1;j<n;j++)
		{
			if(a[j]<a[x])
				x=j;
		}
		if(x!=i)
		{
			a[x]^=a[i];
			a[i]^=a[x];
			a[x]^=a[i];
		}
	}
}
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
void heapSort(int *a,int n)
{
	if(a==NULL||n<=1)
		return;
	for(int i=n/2-1;i>=0;i--)
		heap(a,n,i);
	for(int i=n-1;i>0;i--)
	{
		a[0]^=a[i];
		a[i]^=a[0];
		a[0]^=a[i];
		heap(a,i,0);
	}
}
void QipaoSort(int *a,int n)
{
	if(a==NULL||n<=1)
		return;	
	for(int i=0;i<n-1;i++)
	{
		for(int j=0;j<n-i-1;j++)
		{
			if(a[j]>a[j+1])
			{
				a[j]^=a[j+1];
				a[j+1]^=a[j];
				a[j]^=a[j+1];
			}
		}
	}
}
void QSort(int *a,int n)
{
	if(a==NULL||n<=1)
		return;	
	int i=0;
	int j=n-1;
	int x=a[i];
	while(i<j)
	{
		for(;i<j;j--)
		{
			if(x>a[j])
			{
				a[i++]=a[j];
				break;
			}
		}
		for(;i<j;i++)
		{
			if(x<a[i])
			{
				a[j--]=a[i];
				break;
			}
		}
	}
	a[i]=x;
	QSort(a,i);
	QSort(a+i+1,n-i-1);
}
void merge(int *a,int *b,int low,int m,int high)
{
	int i=low;
	int j=m+1;
	int k=low;
	while(i<=m&&j<=high)
	{
		if(a[i]<a[j])
			b[k++]=a[i++];
		else
			b[k++]=a[j++];
	}
	while(i<=m)
		b[k++]=a[i++];
	while(j<=high)
		b[k++]=a[j++];
}
void mergePass(int *a,int *b,int n,int len)
{
	int i=0;
	while(i+2*len-1<n)
	{
		merge(a,b,i,i+len-1,i+2*len-1);
		i+=2*len;
	}
	if(i+len<n)
		merge(a,b,i,i+len-1,n-1);
	else
	{
		while(i<n)
		{
			b[i]=a[i];
			i++;
		}
	}
}
void mergeSort(int *a,int n)
{
	if(a==NULL||n<=1)
		return;	
	int *b=(int *)malloc(sizeof(int)*n);
	int len=1;
	while(len<n)
	{
		mergePass(a,b,n,len);
		len*=2;
		mergePass(b,a,n,len);
		len*2;
	}
	free(b);
}
#include<stdlib.h>
#define N 1000
#define random(i) (rand()%i)
int a[N];
int flag[N];
int main()
{
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
		
	//insertSort(a,N);
	//shellSort(a,N);
	//selectSort(a,N);
	//heapSort(a,N);
	//QipaoSort(a,N);
	//QSort(a,N);
	mergeSort(a,N);
	for(int i=0;i<N;i++)
	{
		printf("%03d ",a[i]);
		if((i+1)%20==0)\
			printf("\n");
	}
	printf("\n");
	return 0;
}