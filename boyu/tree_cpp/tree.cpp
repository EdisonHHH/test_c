/*#include<iostream>
#include<stack>
using namespace std;
struct BinTreeNode
{
	int info;
	BinTreeNode *llink,*rlink;
};
void createTree(BinTreeNode **ptree)
{
	if(ptree==NULL||*ptree!=NULL)
	{
		return;
	}
	int tmp;
	cin>>tmp;
	if(tmp==0)
	{
		return;
	}
	*ptree=new BinTreeNode;
	(*ptree)->info=tmp;
	(*ptree)->llink=(*ptree)->rlink=NULL;
	createTree(&(*ptree)->llink);
	createTree(&(*ptree)->rlink);
}
void deleteTree(BinTreeNode **ptree)
{
	if(ptree==NULL||*ptree==NULL)
	{
		return;
	}
	deleteTree(&(*ptree)->llink);
	deleteTree(&(*ptree)->rlink);
	delete *ptree;
	*ptree=NULL;
}
void preOrder(BinTreeNode *tree)
{
	if(tree==NULL)
	{
		return;
	}
	cout<<tree->info<<" ";
	preOrder(tree->llink);
	preOrder(tree->rlink);
}
void nPreOrder(BinTreeNode *tree)
{
	if(tree==NULL)
	{
		return;
	}
	stack<BinTreeNode*> st;
	BinTreeNode *p=tree;
	st.push(p);
	while(!st.empty())
	{
		p=st.top();
		st.pop();
		if(p)
		{
			cout<<p->info<<" ";
			st.push(p->rlink);
			st.push(p->llink);
		}
	}
	cout<<endl;
}
void inOrder(BinTreeNode *tree)
{
	if(tree==NULL)
	{
		return;
	}
	inOrder(tree->llink);
	cout<<tree->info<<" ";
	inOrder(tree->rlink);
}
void nInOrder(BinTreeNode *tree)
{
	if(tree==NULL)
	{
		return;
	}
	stack<BinTreeNode*> st;
	BinTreeNode *p=tree;
	while(p||!st.empty())
	{
		while(p)
		{
			st.push(p);
			p=p->llink;
		}
		p=st.top();
		st.pop();
		cout<<p->info<<" ";
		p=p->rlink;
	}
	cout<<endl;
}
void postOrder(BinTreeNode *tree)
{
	if(tree==NULL)
	{
		return;
	}
	postOrder(tree->llink);
	postOrder(tree->rlink);
	cout<<tree->info<<" ";
}
void nPostOrder(BinTreeNode *tree)
{
	if(tree==NULL)
	{
		return;
	}
	stack<BinTreeNode*> st;
	BinTreeNode *p=tree;
	BinTreeNode *pp=NULL;
	while(p||!st.empty())
	{
		while(p)
		{
			st.push(p);
			pp=p->rlink;
			p=p->llink;
			if(p==NULL)
			{
				p=pp;
			}
		}
		p=st.top();
		st.pop();
		cout<<p->info<<" ";
		if(!st.empty()&&st.top()->llink==p)
		{
			p=st.top()->rlink;
		}
		else
		{
			p=NULL;
		}
	}
	cout<<endl;
}
int main()
{
	BinTreeNode *tree=NULL;
	createTree(&tree);
	preOrder(tree);
	cout<<endl;
	nPreOrder(tree);

	inOrder(tree);
	cout<<endl;
	nInOrder(tree);

	postOrder(tree);
	cout<<endl;
	nPostOrder(tree);

	deleteTree(&tree);
	return 0;
}*/
#include<iostream>
#include<stack>
using namespace std;
struct BinTreeNode{
	int info;
	BinTreeNode *llink,*rlink;
};
void createTree(BinTreeNode **ptree)
{
	if(ptree==NULL||*ptree!=NULL)
		return;
	int tmp;
	cin>>tmp;
	if(tmp==0)
		return;
	*ptree=new BinTreeNode;
	(*ptree)->info=tmp;
	(*ptree)->llink=(*ptree)->rlink=NULL;
	createTree(&(*ptree)->llink);
	createTree(&(*ptree)->rlink);
}
void destroyTree(BinTreeNode **ptree)
{
	if(ptree==NULL||*ptree==NULL)
		return;
	destroyTree(&(*ptree)->llink);
	destroyTree(&(*ptree)->rlink);
	delete *ptree;
	*ptree=NULL;
}
void preOrder(BinTreeNode *tree)
{
	if(tree==NULL)
		return;
	cout<<tree->info<<' ';
	preOrder(tree->llink);
	preOrder(tree->rlink);
}
void nPreOrder(BinTreeNode *tree)
{
	if(tree==NULL)
		return;
	stack<BinTreeNode*> st;
	BinTreeNode *p=tree;
	st.push(p);
	while(!st.empty())
	{
		p=st.top();
		st.pop();
		if(p!=NULL)
		{
			cout<<p->info<<' '; 
			st.push(p->rlink);
			st.push(p->llink);
		}
	}
	cout<<endl;
}
void inOrder(BinTreeNode *tree)
{
	if(tree==NULL)
		return;
	inOrder(tree->llink);
	cout<<tree->info<<' ';
	inOrder(tree->rlink);
}
void nInOrder(BinTreeNode *tree)
{
	if(tree==NULL)
		return;
	stack<BinTreeNode*> st;
	BinTreeNode *p=tree;
	while(p||!st.empty())
	{
		while(p)
		{
			st.push(p);
			p=p->llink;
		}
		p=st.top();
		st.pop();
		cout<<p->info<<' ';
		p=p->rlink;
	}
	cout<<endl;
}
void postOrder(BinTreeNode *tree)
{
	if(tree==NULL)
		return;
	postOrder(tree->llink);
	postOrder(tree->rlink);
	cout<<tree->info<<' ';
}
void nPostOrder(BinTreeNode *tree)
{
	if(tree==NULL)
		return;
	stack<BinTreeNode*> st;
	BinTreeNode *p=tree;
	BinTreeNode *pp=NULL;
	while(p||!st.empty())
	{
		while(p)
		{
			st.push(p);
			pp=p->rlink;
			p=p->llink;
			if(p==NULL)
			{
				p=pp;
			}
		}
		p=st.top();
		st.pop();
		cout<<p->info<<' ';
		if(!st.empty()&&st.top()->llink==p)
		{
			p=st.top()->rlink;
		}
		else
		{
			p=NULL;
		}
	}
	cout<<endl;
}
int main()
{
	BinTreeNode *tree=NULL;
	createTree(&tree);
	preOrder(tree);
	cout<<endl;
	nPreOrder(tree);

	inOrder(tree);
	cout<<endl;
	nInOrder(tree);

	postOrder(tree);
	cout<<endl;
	nPostOrder(tree);
	destroyTree(&tree);
	return 0;
}
