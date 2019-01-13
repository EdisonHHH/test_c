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
void createLink(Node **plink)
{
	if(plink==NULL||*plink!=NULL)
		return;
	int num=0;
	Node *p=NULL;
	while(num<N)
	{
		int buf=random(N);
		if(flag[buf]==0)
		{
			flag[buf]=1;
			Node *newNode=new Node;
			newNode->key=buf;
			newNode->next=NULL;
			if(*plink==NULL)
			{
				*plink=newNode;
				p=*plink;
			}
			else
			{
				p->next=newNode;
				p=newNode;
			}
			num++;
		}
	}
	
}
void sortLink(Node **plink)
{
	if(plink==NULL||*plink==NULL)
		return;
	Node *p=(*plink)->next;
	Node *p_pre=*plink;
	while(p)
	{
		Node *q=*plink;
		Node *q_pre=NULL;
		while(q!=p)
		{
			if(q->key>p->key)
				break;
			q_pre=q;
			q=q->next;
		}
		Node *buf=p;
		if(q!=p)
		{
			buf=p_pre;
			p_pre->next=p->next;
			p->next=q;
			if(q_pre==NULL)
				*plink=p;
			else
				q_pre->next=p;
		}
		p_pre=buf;
		p=buf->next;
	}
}
void printLink(Node *link)
{
	if(link==NULL)
		return;
	while(link)
	{
		cout<<link->key<<" ";
		link=link->next;
	}
	cout<<endl;
}
void destroyLink(Node **plink)
{
	if(plink==NULL||*plink==NULL)
		return;
	while(*plink)
	{
		Node *p=(*plink)->next;
		delete *plink;
		*plink=p;
	}
}
int main()
{
	Node *link=NULL;
	createLink(&link);
	printLink(link);
	sortLink(&link);
	printLink(link);
	destroyLink(&link);
	return 0;
}