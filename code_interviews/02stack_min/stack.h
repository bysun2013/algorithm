#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED

#include <stdlib.h>
#include <stdio.h>

#define STACK_INIT_SIZE 50
#define STACK_INCREMNET 20

#define SElemType int

/* min_stack中数据项存储顺序栈中最小数的索引 */
typedef struct min_stack{
	int * top;
	int * base;
	int stacksize;
}min_stack;

typedef struct seq_stack{
	SElemType * top;
	SElemType * base;
	int stacksize;
	min_stack *min;
}stack;

int init_stack(stack *s);
int destroy_stack(stack *s);
int clear_stack(stack *s);

int getlen(stack s);
int is_empty(stack s);
int is_full(stack s);

int get_top(stack s,SElemType *e);
int push(stack *s,SElemType n);
int pop(stack *s,SElemType *n);
int get_min(stack *s, SElemType *n);

int stack_traverse(stack s);

#endif
