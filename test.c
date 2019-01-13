#include<stdio.h>
int main()
{
	int a[12]={1,2,3,4,5,6,7,8,9,10,11,12};
	int (*b)[4];
	b=&a;
	printf("%d\n",(*b)[0]);
	b++;
	printf("%d\n",(*b)[0]);


	int *p[4];
	p[0]=a;
	printf("%d\n",*(++p[0]));
	struct a{
		int *b[4];
	};
	printf("%d\n",sizeof(struct a));
	struct c{
		int (*d)[4];
	};
	printf("%d\n",sizeof(struct c));
	return 0;
}
