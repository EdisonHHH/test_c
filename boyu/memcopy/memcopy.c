#include<stdio.h>
/****
void *memcopy(void *dest,const void *src,int n)
{
	int i;
	char *pdest=(char*)dest;
	const char *psrc=(const char*)src;
	if(pdest>psrc&&pdest<psrc+n){
		for(i=n-1;i>=0;i--){
			pdest[i]=psrc[i];
		}
	}
	else{
		for(i=0;i<n;i++){
			pdest[i]=psrc[i];
		}
	}
	return dest;
}
int main()
{
	int i;
	int a[10]={1,2,3,4,5,6,7,8,9,10};
	memcopy(a+3,a,6*sizeof(int));
	for(i=0;i<10;i++){
		printf("%d ",a[i]);
	}
	printf("\n");
	return 0;
}
*/
void *memcpy(void *dest,void *src,int len)
{
	char *pdest=(char*)dest;
	const char *psrc=(const char*)src;
	if(pdest==NULL||psrc==NULL||len<=0)
		return NULL;
	int i=0;
	if(pdest>psrc&&pdest<psrc+len){
		for(i=len-1;i>=0;i--)
			pdest[i]=psrc[i];
		printf("1\n");
	}
	else{
		for(i=0;i<len;i++)
			pdest[i]=psrc[i];
		printf("2\n");
	}
	return dest;
}
int main()
{
	int i=0;
	int a[10]={1,2,3,4,5,6,7,8,9,10};
	memcpy(&a[2],a,4*sizeof(int));
	for(i=0;i<10;i++)
		printf("%d ",a[i]);
	printf("\n");
	return 0;
}
