#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#define N 100
#define random(i) (rand()%i)
int flag[N];
typedef struct Node{
	int key;
	struct Node *next;
}Node;
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
			Node *newNode=(Node*)malloc(sizeof(Node));
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
		free(p);
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
		printf("%d ",p->key);
		p=p->next;
	}
	printf("\n");
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
	Node *head1= (Node*)malloc(sizeof(Node));
	head1->next=NULL;
	createLink(head1,10);
	sort(head1);
	printLink(head1);
	
	Node *head2=(Node*)malloc(sizeof(Node));
	head2->next=NULL;
	createLink(head2,20);
	sort(head2);
	printLink(head2);
	
	merge(head1,head2);
	free(head2);
	head2=NULL;
	printLink(head1);
	reverseList(head1);
	printLink(head1);
	
	destroyLink(head1);
	free(head1);
	head1=NULL;
	
	return 0;
}
