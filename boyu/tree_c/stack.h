#include"tree.h"
struct stack{
	int MAXMUN;
	int t;
	BinTreeNode **data;
};
typedef struct stack stack;
stack *createStack(int m);
void destroyStack(stack **ppst);
int isFull(stack *pst);
int isEmpty(stack *pst);
void push(stack *pst,BinTreeNode* x);
void pop(stack *pst);
BinTreeNode* top(stack *pst);
