#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
//定义节点
typedef struct data{
    int value;
    struct data *next;

}node;

//初始化node
node *newData(int age){

    //动态分配内存
    node *p = (node *)malloc(sizeof(node));
    p->value = age;
    return p;
}

//判栈空
int isEmpty(node *head){
    if(head->next == NULL){
        return 1;
    }
    return 0;
}

//建立空栈
node *newStack(){

    //建立头结点
    node *head = newData(-1);

    //头结点的下一个节点置空
    head->next = NULL;

    return head;
}

//add element in first 进栈
void pash(node *head, node *p){
    //将元素添加到表头，以实现栈结构

    p->next = head->next;

    head->next = p;

}


//出栈
void pop(node *head){
    if(isEmpty(head)){
        printf("the stack is empty");
        exit(1);
    }
    node *p = head->next;

    head->next = head->next->next;

    free(p);
}

//取栈顶
node *getTop(node *head){
    if(isEmpty(head)){
            return NULL;
    }
    return head->next;

}


int main(){
    node *head = newStack();
    pash(head,newData(1));
    pash(head,newData(2));
    pash(head,newData(3));
    pash(head,newData(4));
    pash(head,newData(5));

    while(!isEmpty(head)){
        printf("%d\n",getTop(head)->value);
        pop(head);
    }
	return 0;
}