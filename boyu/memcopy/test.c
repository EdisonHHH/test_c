#include<stdio.h>
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
	int a[6]={1,2,6,5,4,3};
	fun(a,6);
	for(i=0;i<6;i++){
		printf("%d ",a[i]);	
	}
	printf("\n");
	return 0;
}
