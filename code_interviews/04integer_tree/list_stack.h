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
}stack;

int init_stack(stack *s);
int destroy_stack(stack *s);
int clear_stack(stack *s);

int getlen(stack *s);
int isempty(stack *s);
int isfull(stack *s);

int get_top(stack *s,SElemType *e);
int push(stack *s,SElemType n);
int pop(stack *s,SElemType *n);

int print_stack(stack *s);


#endif // LIST_STACK_H_INCLUDED
