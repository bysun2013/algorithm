#ifndef LIST_STACK_H_INCLUDED
#define LIST_STACK_H_INCLUDED

#include <stdlib.h>
#include <stdio.h>

#define SElemType int

typedef struct Node{
    SElemType value;
    struct Node * next;
}*node;
typedef struct list_stack{
    node base,top;
    int stacksize;
}stack,*stackptr;

int initStack(stack *s);
int destroyStack(stack *s);
int clearStack(stack *s);

int getLen(stack *s);
int isEmpty(stack *s);
int isFull(stack *s);

int getTop(stack *s,SElemType *e);
int push(stack *s,SElemType n);
int pop(stack *s,SElemType *n);

int stackTraverse(stack *s);


#endif // LIST_STACK_H_INCLUDED
