#include<iostream>
#include<stack>
using namespace std;
const bool black = 0;
const bool red = 1;
struct RBNode{
	int key;
	bool color;
	RBNode *llink,*rlink,*parent;
};
class RBTree{
public:
	RBTree();
	~RBTree();
	void insertNode(int key);                       
	void deleteNode(int key);
	void nPreOrder();
	void nInOrder();
	void nPostOrder();		
private:
	void destroy(RBNode **proot);     			//use in ~RBTree();
	RBNode *createNode(int key);      			//create a rb_tree node
	void insertFixup(RBNode *pnode);  			//fix after insert a node
	RBNode *searchNode(int key);      			//find a node which key is key, use in deleteNode
	void transplant(RBNode *v0,RBNode *v1);  	// use in deleteNode
	RBNode *minNode(RBNode *x);             	//use in deleteNode
	void deleteFixup(RBNode *pnode);      		//fix after delete a node
	RBNode *rotate_right(RBNode *a);
	RBNode *rotate_left(RBNode *a);
	RBNode *root;
	RBNode *m_null;
};

RBTree::RBTree()
{
	m_null = new RBNode;
	m_null->color = black;
	m_null->llink=m_null->rlink = m_null;
	root=m_null;
}

RBTree::~RBTree()
{
	if(root!=m_null){
		destroy(&root);
		root=NULL;
	}
	delete m_null;
	m_null=NULL;
}

void RBTree::insertNode(int key)
{
	RBNode *p=root;
	RBNode *q=m_null;
	while(p!=m_null){
		q=p;
		if(key==p->key){
			return;
		}
		else if(key<p->key){
			p=p->llink;
		}
		else{
			p=p->rlink;
		}
	}	
	RBNode *newNode=createNode(key);
	if(q==m_null){
		root=newNode;
		root->color=black;
		newNode->parent=m_null;
		return;
	}
	if(key<q->key){
		q->llink=newNode;
	}
	else{
		q->rlink=newNode;
	}
	newNode->parent=q;
	insertFixup(newNode);
}

void RBTree::insertFixup(RBNode *pnode)
{
	RBNode *parent=pnode->parent;
	RBNode *grandParent=m_null;
	while(parent!=m_null&&parent->color==red){
		grandParent=parent->parent;
		if(parent==grandParent->llink){
			RBNode *uncle=grandParent->rlink;
			if(uncle->color==red){
				parent->color=black;
				uncle->color=black;
				grandParent->color=red;
				pnode=grandParent;
				parent=pnode->parent;
			}
			else{
				if(pnode==parent->rlink){
					pnode=rotate_left(parent);
					parent=pnode->parent;
					grandParent=parent->parent;
				}
				parent->color=black;
				grandParent->color=red;
				rotate_right(grandParent);
			}
		}
		else{
			RBNode *uncle=grandParent->llink;
			if(uncle->color==red){
				parent->color=black;
				uncle->color=black;
				grandParent->color=red;
				pnode=grandParent;
				parent=pnode->parent;
			}
			else{
				if(pnode==parent->llink){
					pnode=rotate_right(parent);
					parent=pnode->parent;
					grandParent=parent->parent;
				}
				parent->color=black;
				grandParent->color=red;
				rotate_left(grandParent);
			}
		}
	}
	root->color=black;
}

RBNode *RBTree::searchNode(int key)
{
	RBNode *p=root;
	while(p!=m_null){
		if(key==p->key)
			return p;
		else if(key<p->key)
			p=p->llink;
		else 
			p=p->rlink;
	}
	return m_null;
}

void RBTree::transplant(RBNode *v0,RBNode *v1)
{
	if(v0==root)
		root=v1;
	else if(v0==v0->parent->llink)
		v0->parent->llink=v1;
	else
		v0->parent->rlink=v1;
	v1->parent=v0->parent;
}

RBNode *RBTree::minNode(RBNode *x)
{
	while(x->llink!=m_null)
		x=x->llink;
	return x;
}

void RBTree::deleteNode(int key)
{
	RBNode *delNode=searchNode(key);
	if(delNode==m_null)
		return;
	RBNode *realDel=delNode;
	RBNode *replace=m_null;
	if(delNode->rlink==m_null)
		replace=delNode->llink;
	else if(delNode->llink==m_null)
		replace=delNode->rlink;
	else{
		realDel=minNode(delNode->rlink);
		replace=realDel->rlink;
		delNode->key=realDel->key;
	}
	transplant(realDel,replace);
	if(realDel->color==black)
		deleteFixup(replace);
	delete realDel;
}

void RBTree::deleteFixup(RBNode *delNode)
{
	RBNode *p=delNode;
	while(p!=root&&p->color==black){
		RBNode *parent=p->parent;
		if(p==parent->llink){
			RBNode *slibing=parent->rlink;
			if(slibing->color==red){
				parent->color=red;
				slibing->color=black;
				rotate_left(parent);
				slibing=parent->rlink;
			}	
			if(slibing->llink->color==black&&slibing->rlink->color==black){
				slibing->color=red;
				p=p->parent;
			}
			else{
				if(slibing->rlink->color==black){
					slibing->color=red;
					slibing->llink->color=black;
					rotate_right(slibing);
					slibing=slibing->parent;
				}
				slibing->color=parent->color;
				parent->color=black;
				slibing->rlink->color=black;
				rotate_left(parent);
				p=root;
			}
		}
		else{
			RBNode *slibing=parent->llink;
			if(slibing->color==red){
				slibing->color=black;
				parent->color=red;
				rotate_right(parent);
				slibing=parent;
			}
			if(slibing->llink->color==black&&slibing->rlink->color==black){
				slibing->color=red;
				p=parent;
			}
			else{
				if(slibing->llink->color==black){
					slibing->color=red;
					slibing->rlink->color=black;
					rotate_left(slibing);
					slibing=slibing->parent;
				}
				slibing->color=parent->color;
				parent->color=black;
				slibing->llink->color=black;
				rotate_right(parent);
				p=root;
			}
		}
	}
	p->color=black;
}
RBNode *RBTree::rotate_right(RBNode *a)
{
	RBNode *b=a->llink;
	if(b==m_null)
		return a;
	a->llink=b->rlink;
	b->rlink->parent=a;
	if(root==a){
		root=b;
		b->parent=m_null;
	}
	else{
		if(a->parent->llink==a)
			a->parent->llink=b;
		else
			a->parent->rlink=b;
		b->parent=a->parent;
	}
	b->rlink=a;
	a->parent=b;
	return a;
}
RBNode *RBTree::rotate_left(RBNode *a)
{
	RBNode *b=a->rlink;
	if(b==m_null)
		return a;
	a->rlink=b->llink;
	b->llink->parent=a;
	if(root==a){
		root=b;
		b->parent=m_null;
	}
	else{
		if(a->parent->llink==a)
			a->parent->llink=b;
		else
			a->parent->rlink=b;
		b->parent=a->parent;
	}
	b->llink=a;
	a->parent=b;
	return a;
}

void RBTree::destroy(RBNode **proot)
{
	if(*proot==m_null)
		return;
	destroy(&(*proot)->llink);
	destroy(&(*proot)->rlink);
	delete *proot;
	*proot=m_null;
}
RBNode *RBTree::createNode(int key)
{
	RBNode *p=new RBNode;
	if(p){
		p->color=red;
		p->key=key;
		p->llink=p->rlink=p->parent=m_null;
	}
	return p;
}

void RBTree::nPreOrder()
{
	if(root==m_null)
		return;
	stack<RBNode*> st;
	RBNode *p=root;
	st.push(p);
	while(!st.empty()){
		p=st.top();
		st.pop();
		if(p!=m_null){
			cout<<p->key<<" ";
			st.push(p->rlink);
			st.push(p->llink);
		}
	}
	cout<<endl;
}

void RBTree::nInOrder()
{
	if(root==m_null)
		return;
	stack<RBNode*> st;
	RBNode *p=root;
	while(p!=m_null||!st.empty()){
		while(p!=m_null){
			st.push(p);
			p=p->llink;
		}
		p=st.top();
		st.pop();
		cout<<p->key<<" ";
		p=p->rlink;
	}
	cout<<endl;
}

void RBTree::nPostOrder()
{
	if(root==m_null)
		return;
	stack<RBNode*> st;
	RBNode *p=root;
	RBNode *pp=m_null;
	while(p!=m_null||!st.empty()){
		while(p!=m_null){
			st.push(p);
			pp=p->rlink;
			p=p->llink;
			if(p==m_null)
				p=pp;
		}
		p=st.top();
		st.pop();
		cout<<p->key<<" ";
		if(!st.empty()&&st.top()->llink==p)
			p=st.top()->rlink;
		else
			p=m_null;
	}
	cout<<endl;
}
int main()
{
	RBTree tree;
	int x;
	cin>>x;
	while(x){
		tree.insertNode(x);
		cin>>x;
	}
	tree.nPreOrder();
	tree.nInOrder();
	tree.nPostOrder();
	cin.clear();
	cin>>x;
	while(x){
		tree.deleteNode(x);
		tree.nPreOrder();
		tree.nInOrder();
		tree.nPostOrder();
		cin>>x;
	}
	return 0;
}
