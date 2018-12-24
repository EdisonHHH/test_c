#include<iostream>
#include<fstream>
#include<stack>
using namespace std;
const bool black = false;
const bool red = true;
struct RBNode
{
	int key;
	bool color;
	RBNode *llink, *rlink, *parent;
};
class RBTree
{
	static int max(int x,int y);                        //获得两个数中大的数
	static int len_int(int x);                          //获得节点的长度（包含颜色标记）
	static void int_to_str(int x,char *str,bool color); //降结点键值转换为字符数组（包含颜色标记）
	static void showBuf(char **buf,int x,int y);        //打印二维字符数组（映射的红黑树）
public:
	RBTree();
	~RBTree();
	int insertNode(int key);                            //插入一个结点
	int deleteNode(int key);                            //删除一个结点

private:
	void insertFixup(RBNode *pnode);                    //插入结点后调整
	void deleteFixup(RBNode *pnode);                    //删除结点后调整
	RBNode *rotate_left(RBNode *a);                     //左旋
	RBNode *rotate_right(RBNode *a);                    //右旋
	RBNode *createNode(int key);                        //生成一个结点
	void destroy(RBNode *pnode);                        //销毁一棵树
	RBNode *root;                                       //根结点
	RBNode *m_null;
	
public:
	void show();                                        //图形显示一棵树
private:
	int getHeight(RBNode *tree);
	int getWidth(RBNode *tree);
	int getRootPos(RBNode *tree,int x);
	void printInBuf(RBNode *tree,char **buf, int x, int y);
};
RBTree::RBTree()
{
	m_null = new RBNode;
	if (m_null)
	{
		m_null->color = black;
		m_null->llink = m_null->rlink = m_null->parent = m_null;
	}
	root = m_null;
}
RBTree::~RBTree()
{
	destroy(root);
	root = NULL;
	m_null = NULL;
}
int RBTree::insertNode(int key)
{
	RBNode *p = root;
	RBNode *parent = m_null;
	while (p != m_null)
	{
		if (p->key == key)
		{
			return -1;
		}
		parent = p;
		if (key < p->key)
		{
			p = p->llink;
		}
		else
		{
			p = p->rlink;
		}
	}
	RBNode *newnode = createNode(key);
	if (parent == m_null)
	{
		root = newnode;
		newnode->color = black;
	}
	else
	{
		if (key < parent->key)
		{
			parent->llink = newnode;
		}
		else
		{
			parent->rlink = newnode;
		}
		newnode->parent = parent;
		insertFixup(newnode);
	}
	return 0;
}
void RBTree::insertFixup(RBNode *pnode)
{
	RBNode *parent = pnode->parent;
	RBNode *grandparent = m_null;
	while (parent != m_null&&parent->color == red)
	{
		grandparent = parent->parent;
		if (parent == grandparent->llink)
		{
			RBNode *uncle = grandparent->rlink;
			if (uncle->color == red)
			{
				parent->color = black;
				uncle->color = black;
				grandparent->color = red;
				pnode = grandparent;
				parent = pnode->parent;
			}
			else
			{
				if (pnode == parent->rlink)
				{
					pnode = rotate_left(parent);
					parent = pnode->parent;
				}
				parent->color = black;
				grandparent->color = red;
				rotate_right(grandparent);
			}
		}
		else
		{
			RBNode *uncle = grandparent->llink;
			if (uncle->color == red)
			{
				parent->color = black;
				uncle->color = black;
				grandparent->color = red;
				pnode = grandparent;
				parent = pnode->parent;
			}
			else
			{
				if (pnode == parent->llink)
				{
					pnode = rotate_right(parent);
					parent = pnode->parent;
				}
				parent->color = black;
				grandparent->color = red;
				rotate_left(grandparent);
			}
		}
	}
	root->color = black;
}
int RBTree::deleteNode(int key)
{
	RBNode *delNode = root;
	while (delNode != m_null)
	{
		if (key == delNode->key)
		{
			break;
		}
		else if (key < delNode->key)
		{
			delNode = delNode->llink;
		}
		else
		{
			delNode = delNode->rlink;
		}
	}
	if (delNode == m_null)
	{
		return -1;
	}
	RBNode *realDel = delNode;
	RBNode *replace = m_null;
	if (delNode->llink == m_null)
	{
		replace = delNode->rlink;
	}
	else if (delNode->rlink == m_null)
	{
		replace = delNode->llink;
	}
	else
	{
		realDel = delNode->rlink;
		while (realDel->llink != m_null)
		{
			realDel = realDel->llink;
		}
		replace = realDel->rlink;
		delNode->key = realDel->key;
	}
	if (root == realDel)
	{
		root = replace;
		replace->parent = m_null;
	}
	else
	{
		if (realDel->parent->llink == realDel)
		{
			realDel->parent->llink = replace;
		}
		else
		{
			realDel->parent->rlink = replace;
		}
		replace->parent = realDel->parent;
	}
	if (realDel->color == black)
	{
		deleteFixup(replace);
	}
	delete realDel;
	return 0;
}
void RBTree::deleteFixup(RBNode *pnode)
{
	RBNode *p = pnode;
	RBNode *parent = m_null;
	RBNode *sibling = m_null;
	while (p != root&&p->color == black)
	{
		parent = p->parent;
		if (p == parent->llink)
		{
			sibling = parent->rlink;
			if (sibling->color == red)
			{
				sibling->color = black;
				parent->color = red;
				rotate_left(parent);
				sibling = parent->rlink;
			}
			if (sibling->llink->color == black&&sibling->rlink->color == black)
			{
				sibling->color = red;
				p = parent;
			}
			else
			{
				if (sibling->rlink->color == black)
				{
					sibling->color = red;
					sibling->llink->color = black;
					rotate_right(sibling);
					sibling = sibling->parent;
				}
				sibling->color = parent->color;
				parent->color = black;
				sibling->rlink->color = black;
				rotate_left(parent);
				p = root;
			}
		}
		else
		{
			sibling = parent->llink;
			if (sibling->color == red)
			{
				sibling->color = black;
				parent->color = red;
				rotate_right(parent);
				sibling = parent->llink;
			}
			if (sibling->llink->color == black&&sibling->rlink->color == black)
			{
				sibling->color = red;
				p = parent;
			}
			else
			{
				if (sibling->llink->color == black)
				{
					sibling->color = red;
					sibling->rlink->color = black;
					rotate_left(sibling);
					sibling = sibling->parent;
				}
				sibling->color = parent->color;
				parent->color = black;
				sibling->llink->color = black;
				rotate_right(parent);
				p = root;
			}
		}
	}
	p->color = black;
}
RBNode *RBTree::rotate_left(RBNode *a)
{
	RBNode *b = a->rlink;
	a->rlink = b->llink;
	b->llink->parent = a;
	if (root == a)
	{
		root = b;
		b->parent = m_null;
	}
	else
	{
		if (a->parent->llink == a)
		{
			a->parent->llink = b;
		}
		else
		{
			a->parent->rlink = b;
		}
		b->parent = a->parent;
	}
	b->llink = a;
	a->parent = b;
	return a;
}
RBNode *RBTree::rotate_right(RBNode *a)
{
	RBNode *b = a->llink;
	a->llink = b->rlink;
	b->rlink->parent = a;
	if (root == a)
	{
		root = b;
		b->parent = m_null;
	}
	else
	{
		if (a->parent->llink == a)
		{
			a->parent->llink = b;
		}
		else
		{
			a->parent->rlink = b;
		}
		b->parent = a->parent;
	}
	b->rlink = a;
	a->parent = b;
	return a;
}
RBNode *RBTree::createNode(int key)
{
	RBNode *p = new RBNode;
	if (p)
	{
		p->key = key;
		p->color = red;
		p->llink = p->rlink = p->parent = m_null;
	}
	return p;
}
void RBTree::destroy(RBNode *pnode)
{
	if (pnode == m_null)
	{
		return;
	}
	destroy(pnode->llink);
	destroy(pnode->rlink);
	delete pnode;
}

int RBTree::max(int x,int y)
{
	return (x>y)? x:y;
}
int RBTree::len_int(int x)
{
	int len=0;
	while(x)
	{
		len++;
		x/=10;
	}
	return len+1;    //加颜色标记
}
void RBTree::int_to_str(int x,char *str,bool color)
{
	int len=len_int(x);
	while(x)
	{
		str[--len]=x%10+'0';
		x/=10;
	}
	if(color==red)
		str[0]='R';
	else if(color==black)
		str[0]='B';
}
ofstream output;
void RBTree::showBuf(char **buf,int x,int y)
{
	
	for(int i=0; i<y; i++){
	    for(int j=0; j<x; j++)
	        output<<(buf[i][j]==0? ' ':buf[i][j]);
	    output<<endl;
	}
	output<<"=================================================================================="<<endl;
}
  
int RBTree::getHeight(RBNode *tree)
{
	if(tree==m_null)
		return 0;
    return 2 +max(getHeight(tree->llink),getHeight(tree->rlink));
}

int RBTree::getWidth(RBNode *tree)
{

	if(tree==m_null)
		return 0;
    return len_int(tree->key)+getWidth(tree->llink)+getWidth(tree->rlink);
}

int RBTree::getRootPos(RBNode *tree,int x)
{
	if(tree==m_null)
		return x;
	return x + getWidth(tree->llink);
}

void RBTree::printInBuf(RBNode *tree,char **buf, int x, int y)
{
	int root_len=len_int(tree->key);
	int p1 = getRootPos(tree->llink,x);
	int p2 = getRootPos(tree,x);
	int p3 = tree->rlink==m_null? p2 : getRootPos(tree->rlink,p2+root_len);

	buf[y][p2] = '|';
	for(int i=p1; i<=p3; i++) buf[y+1][i]='-';
	int_to_str(tree->key,&buf[y+1][p2],tree->color);
	if(p1<p2) buf[y+1][p1] = '/';
	if(p3>p2) buf[y+1][p3] = '\\';
	if(tree->llink!=m_null) printInBuf(tree->llink,buf,x,y+2);
	if(tree->rlink!=m_null)printInBuf( tree->rlink,buf,p2+root_len,y+2);
}

void RBTree::show()
{
	RBNode *tree=root;
	if(tree==m_null)
		return;
	int x=getWidth(tree);
	int y=getHeight(tree);
	char **buf=new char*[y];
	for(int i=0;i<y;i++)
		buf[i]=new char[x];
	for(int i=0;i<y;i++)
		for(int j=0;j<x;j++)
			buf[i][j]=0;
	printInBuf(tree,buf,0,0);
	showBuf(buf,x,y);
	for(int i=0;i<y;i++)
		delete[]buf[i];
	delete[]buf;
}
#include<stdlib.h>
#define N 200
#define random(i) (rand()%i)
int main()
{
	output.open("1");
	RBTree tree;
	int num=0;
	while(num<N)
	{
		int buf=random(N);
		if(buf==0) buf=N;
		if(tree.insertNode(buf)==0)
		{
			num++;
			tree.show();
		}
	}

	num=0;
	while(num<N)
	{
		int buf=random(N);
		if(buf==0) buf=N;
		if(tree.deleteNode(buf)==0)
		{
			num++;
			tree.show();
		}
	}
	
	return 0;
}
