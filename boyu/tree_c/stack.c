#include<malloc.h>
#include"stack.h"

stack *createStack(int m)
{
	stack *pst=(stack*)malloc(sizeof(stack));
	if(pst){
		pst->data=(BinTreeNode**)malloc(sizeof(BinTreeNode*)*m);
		if(pst->data){
			pst->MAXMUN=m;
			pst->t=-1;
		}
		else{
			free(pst);
			pst=NULL;
		}
	}
	return pst;
}
void destroyStack(stack **ppst)
{
	if(ppst==NULL||*ppst==NULL)
	{
		return;
	}
	free((*ppst)->data);
	free(*ppst);
	*ppst=NULL;
}
int isFull(stack *pst)
{
	return pst->t==pst->MAXMUN-1;
}
int isEmpty(stack *pst)
{
	return pst->t==-1;
}
void push(stack *pst,BinTreeNode* x)
{
	if(pst==NULL)
	{
		return;
	}
	if(isFull(pst))
	{
		return;
	}
	pst->t++;
	pst->data[pst->t]=x;
}
void pop(stack *pst)
{
	if(pst==NULL||isEmpty(pst))
	{
		return;
	}
	pst->t--;
}
BinTreeNode* top(stack *pst)
{
	if(pst==NULL||isEmpty(pst))
	{
		return;
	}
	return pst->data[pst->t];
}
