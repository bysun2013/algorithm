#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED
/*
* the value returned is defined as follows:
* 	0:OK
*	1:ERROR
*/
#include <stdlib.h>
#include <stdio.h>

#define STACK_INIT_SIZE 50
#define STACK_INCREMNET 20

#define SElemType int     //type of stack can be changed here, we use int for example
typedef struct SeqStack{
	SElemType * top;
	SElemType * base;
	int stacksize;
}stack;

int initStack(stack *s);
int destroyStack(stack *s);
int clearStack(stack *s);

int getLen(stack s);
int isEmpty_S(stack s);
int isFull_S(stack s);

int getTop(stack s,SElemType *e);
int push(stack *s,SElemType n);
int pop(stack *s,SElemType *n);

int stackTraverse(stack s);


#endif
