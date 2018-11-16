#include<stdio.h>
#include<malloc.h>
#include"stack.h"
//#include"tree.h"

void createTree(BinTreeNode **ptree)
{
	if(ptree==NULL||*ptree!=NULL){
		return;
	}
	int tmp;
	scanf("%d",&tmp);
	if(tmp==0){
		return;
	}	
	*ptree=(BinTreeNode*)malloc(sizeof(BinTreeNode));
	(*ptree)->info=tmp;
	(*ptree)->llink=(*ptree)->rlink=NULL;
	createTree(&(*ptree)->llink);
	createTree(&(*ptree)->rlink);
}
void destroyTree(BinTreeNode **ptree)
{
	if(ptree==NULL||*ptree==NULL){
		return;
	}
	destroyTree(&(*ptree)->llink);
	destroyTree(&(*ptree)->rlink);
	free(*ptree);
	*ptree=NULL;
}

void preOrder(BinTreeNode *tree)
{
	if(tree==NULL){
		return;
	}
	printf("%d ",tree->info);
	preOrder(tree->llink);
	preOrder(tree->rlink);
}
void nPreOrder(BinTreeNode *tree)
{
	if(tree==NULL){
		return;
	}
	stack *pst=createStack(100);
	BinTreeNode *p=tree;
	push(pst,p);
	while(!isEmpty(pst))
	{
		p=top(pst);
		pop(pst);
		if(p)
		{
			printf("%d ",p->info);
			push(pst,p->rlink);
			push(pst,p->llink);
		}
	}
	printf("\n");
	destroyStack(&pst);
		
}
void inOrder(BinTreeNode *tree)
{
	if(tree==NULL)
	{
		return;
	}
	inOrder(tree->llink);
	printf("%d ",tree->info);
	inOrder(tree->rlink);
}
void nInOrder(BinTreeNode *tree)
{
	if(tree==NULL)
	{
		return;
	}
	stack *pst=createStack(100);
	BinTreeNode *p=tree;
	while(p||!isEmpty(pst))
	{
		while(p)
		{
			push(pst,p);
			p=p->llink;
		}
		p=top(pst);
		pop(pst);
		printf("%d ",p->info);
		p=p->rlink;
	}
	printf("\n");
	destroyStack(&pst);
}
void postOrder(BinTreeNode *tree)
{
	if(tree==NULL)
	{
		return;
	}
	postOrder(tree->llink);
	postOrder(tree->rlink);
	printf("%d ",tree->info);
}
void nPostOrder(BinTreeNode *tree)
{
	if(tree==NULL)
	{
		return;
	}
	stack *pst=createStack(100);
	BinTreeNode *p=tree;
	BinTreeNode *pp=NULL;
	while(p||!isEmpty(pst))
	{
		while(p)
		{
			push(pst,p);
			pp=p->rlink;
			p=p->llink;
			if(p==NULL)
			{
				p=pp;
			}	
		}
		p=top(pst);
		pop(pst);
		printf("%d ",p->info);
		if(!isEmpty(pst)&&top(pst)->llink==p)
		{
			p=top(pst)->rlink;
		}
		else
		{
			p=NULL;
		}
	}
	printf("\n");
}
int main()
{
	BinTreeNode *tree=NULL;
	createTree(&tree);
	preOrder(tree);
	printf("\n");
	nPreOrder(tree);

	inOrder(tree);
	printf("\n");
	nInOrder(tree);

	postOrder(tree);
	printf("\n");
	nPostOrder(tree);
	destroyTree(&tree);
	return 0;
}
