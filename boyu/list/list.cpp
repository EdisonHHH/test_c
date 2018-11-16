#include<iostream>
using namespace std;
struct Node{
	int key;
	Node *next;
};
typedef struct Node *List;
void createList(List *plist)
{
	if(plist==NULL||*plist!=NULL)
	{
		return;
	}
	int tmp;
	Node *p=NULL;
	Node *q=NULL;
	cin>>tmp;
	while(tmp)
	{
		p=new Node;
		p->key=tmp;
		p->next=NULL;
		if(*plist==NULL)
		{
			*plist=p;
			q=p;
		}
		else
		{
			q->next=p;
			q=q->next;
		}
		cin>>tmp;
	}
	
}
void destroyList(List *plist)
{
	if(plist==NULL||*plist==NULL)
	{
		return;
	}
	Node *p=*plist;
	while(*plist)
	{
		p=(*plist)->next;
		delete *plist;
		*plist=p;
	}
}
void reverseList(List *plist)
{
	if(plist==NULL||*plist==NULL)
	{
		return;
	}
	Node *p=*plist;
	Node *q=p->next;
	Node *r=NULL;
	while(q)
	{
		r=q->next;
		q->next=p;
		p=q;
		q=r;
	}
	(*plist)->next=NULL;
	*plist=p;
}
void printList(List list)
{
	if(list==NULL)
	{
		return;
	}
	while(list)
	{
		cout<<list->key<<' ';
		list=list->next;
	}
	cout<<endl;
}
int main()
{
	List list=NULL;
	createList(&list);
	printList(list);
	reverseList(&list);
	printList(list);
	destroyList(&list);
	return 0;
}
