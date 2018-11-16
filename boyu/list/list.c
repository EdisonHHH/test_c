/*
#include<stdio.h>
#include<malloc.h>
typedef struct Node* pNode;
struct Node
{
	int info;
	pNode next;
};
typedef struct Node* List;
void createList(List* plist)
{
	if(plist==NULL||*plist!=NULL)
	{
		return;
	}
	int tmp;
	scanf("%d",&tmp);
	if(tmp==0)
	{
		return;
	}
	*plist=(pNode)malloc(sizeof(struct Node));
	(*plist)->info=tmp;
	(*plist)->next=NULL;
	pNode p=*plist;
	while(1)
	{
		scanf("%d",&tmp);
		if(tmp==0)
		{
			return;
		}
		p->next=(pNode)malloc(sizeof(struct Node));
		p->next->info=tmp;
		p->next->next=NULL;
		p=p->next;
	}
}
void deleteList(pNode *pList)
{
	if(pList==NULL||*pList==NULL)
	{
		return;
	}
	pNode p=*pList;
	while(p)
	{
		*pList=p->next;
		free(p);
		p=*pList;
	}
}
void printList(List list)
{
	if(list==NULL)
	{
		return;
	}
	while(list)
	{
		printf("%d ",list->info);
		list=list->next;
	}
	printf("\n");
}
void printList_fromT(List list)
{
	if(list==NULL)
	{
		return;
	}
	printList_fromT(list->next);
	printf("%d ",list->info);
}
List reverseList(List list)
{
	if(list==NULL)
	{
		return;
	}
	pNode buf=list;
	pNode p=list->next;
	pNode q=NULL;
	while(p)
	{
		q=p->next;
		p->next=buf;
		buf=p;
		p=q;
	}
	list->next=NULL;
	list=NULL;
	return buf;
}
int main()
{
	List list=NULL;
	createList(&list);
	printList(list);
	printList_fromT(list);
	printf("\n");

	list=reverseList(list);
	printList(list);
	printList_fromT(list);
	printf("\n");

	deleteList(&list);
	return 0;
}
*/
#include<stdio.h>
#include<malloc.h>
struct Node{
	int info;
	struct Node *link;
};
typedef struct Node* List;
void createList(List *plist)
{
	if(plist==NULL||*plist!=NULL)
	{
		return;
	}
	int tmp;
	scanf("%d",&tmp);
	if(tmp==0)
	{
		return;
	}
	*plist=(List)malloc(sizeof(struct Node));
	if(*plist==NULL)
	{
		return;
	}
	(*plist)->info=tmp;
	(*plist)->link=NULL;
	List p=*plist;
	while(1)
	{
		scanf("%d",&tmp);
		if(tmp==0)
		{
			break;
		}
		p->link=(List)malloc(sizeof(struct Node));
		if(p->link==NULL)
		{
			return;
		}
		p->link->info=tmp;
		p->link->link=NULL;
		p=p->link;
	}
}
void destroyList(List *plist)
{
	if(plist==NULL||*plist==NULL)
	{
		return;
	}
	List p=*plist;
	while(p)
	{
		*plist=p->link;
		free(p);
		p=*plist;
	}
}
void reverse_list(List *plist)
{
	if(plist==NULL||*plist==NULL)
	{
		return;
	}
	List q=*plist;
	List p=(*plist)->link;
	List r=NULL;
	while(p)
	{
		r=p->link;
		p->link=q;
		q=p;
		p=r;
	}
	(*plist)->link=NULL;
	*plist=q;
}
void print_list(List list)
{
	if(list==NULL)
	{
		return;
	}
	while(list)
	{
		printf("%d ",list->info);
		list=list->link;
	}
	printf("\n");
}
int main()
{
	List list=NULL;
	createList(&list);
	print_list(list);
	reverse_list(&list);
	print_list(list);
	destroyList(&list);
	return 0;
}
