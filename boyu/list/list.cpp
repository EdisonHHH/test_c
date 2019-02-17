/*
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
*/
#include<iostream>
using namespace std;
#include<stdlib.h>
#define N 100
#define random(i) (rand()%i)
int flag[N];
struct Node{
	int key;
	Node *next;
};
void createLink(Node *head,int len)
{
	if(head==0||head->next!=NULL)
		return;
	int num=0;
	Node *p=head;
	while(num<len)
	{
		int tmp=random(N);
		if(flag[tmp]==0)
		{
			flag[tmp]=1;
			num++;
			Node *newNode=new Node;
			newNode->key=tmp;
			newNode->next=NULL;
			p->next=newNode;
			p=newNode;
		}
	}
}
void destroyLink(Node *head)
{
	if(head==NULL||head->next==NULL)
		return;
	Node *p=head->next;
	while(p)
	{
		Node *p_next=p->next;
		delete p;
		p=p_next;
	}
	head->next=NULL;
}
void printLink(Node *head)
{
	if(head==NULL||head->next==NULL)
		return;
	Node *p=head->next;
	while(p)
	{
		cout<<p->key<<" ";
		p=p->next;
	}
	cout<<endl;
}
void sort(Node *head)
{
	if(head==NULL||head->next==NULL)
		return;
	Node *p_pre=head->next;
	Node *p=p_pre->next;
	while(p)
	{
		Node *q_pre=head;
		Node *q=head->next;
		while(q!=p)
		{
			if(q->key>p->key)
				break;
			q_pre=q;
			q=q->next;
		}
		if(q!=p)
		{
			p_pre->next=p->next;
			q_pre->next=p;
			p->next=q;
			
		}
		else
			p_pre=p;
		p=p_pre->next;
	}
}
void reverseList(Node *head)
{
	if(head==NULL||head->next==NULL)
		return;
	Node *p=head->next;
	Node *q=p->next;
	Node *r=NULL;
	while(q)
	{
		r=q->next;
		q->next=p;
		if(p==head->next)
			p->next=NULL;
		p=q;
		q=r;
	}
	head->next=p;
}
void merge(Node *head1,Node *head2)
{
	if(head1==NULL||head2==NULL)
		return;
	Node *p=head1->next;
	Node *q=head2->next;
	if(p->key>q->key)
		head1->next=q;
	while(p&&q)
	{
		Node *p_next=p->next;
		Node *q_next=q->next;
		if(p->key<q->key)
		{
			while(p_next&&p_next->key<q->key)
			{
				p=p_next;
				p_next=p->next;
			}
			p->next=q;
			p=p_next;
		}
		else
		{
			while(q_next&&q_next->key<p->key)
			{
				q=q_next;
				q_next=q->next;
			}
			q->next=p;
			q=q_next;
		}
	}
}
int main()
{
	Node *head1=new Node;
	head1->next=NULL;
	createLink(head1,10);
	sort(head1);
	printLink(head1);
	
	Node *head2=new Node;
	head2->next=NULL;
	createLink(head2,20);
	sort(head2);
	printLink(head2);
	
	merge(head1,head2);
	delete head2;
	head2=NULL;
	printLink(head1);
	reverseList(head1);
	printLink(head1);
	
	destroyLink(head1);
	delete head1;
	head1=NULL;
	
	return 0;
}
