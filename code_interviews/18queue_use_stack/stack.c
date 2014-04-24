#include "stack.h"

int initStack(stack *s){
    s->base=(SElemType *)malloc(STACK_INIT_SIZE*sizeof(SElemType));
    if(!s->base) return 1;
    s->top=s->base;
    s->stacksize=STACK_INIT_SIZE;
//    printf("\nA new stack has been established!\n");
    return 0;
}

int destroyStack(stack *s){
    if(!s)
        return 1;
    free(s->base);
    s->base=s->top=NULL;
    s->stacksize=0;
//    printf("\nThe stack has been destroyed!\n");
    return 0;
}
int clearStack(stack *s){
    if(!s)
        return 1;
    s->top=s->base;
    return 0;
}

int getLen(stack s){
	return (s.top-s.base);
}
int isEmpty_S(stack s){
	return s.base==s.top;
}
int isFull_S(stack s){
	return (s.top-s.base==s.stacksize);
}

int getTop(stack s,SElemType *e){
    if(s.base==s.top)
        return 0;
    *e=*(s.top-1);
    return 1;
}
int push(stack *s,SElemType n){
    if(s->top-s->base>=s->stacksize)
    {
        s->base=(SElemType *)realloc(s->base,sizeof(SElemType)*(s->stacksize+STACK_INCREMNET));
        if(!s->base)
            return 0;
        s->top=s->base+s->stacksize;
        s->stacksize+=STACK_INCREMNET;
    }
	*s->top++=n;
	return 1;
}
int pop(stack *s,SElemType *n){
    if(s->base==s->top)
        return 0;
	*n= *(--s->top);
	return 1;
}

int stackTraverse(stack s){
    SElemType* e;
    int i=0;
    if(s.top==s.base){
       printf("This stack is empty!");
       return 1;
       }

    e=s.top-1;
    for(;e>=s.base;e--,i++){
         printf("%d\t",*e);
         if(i%6==5)
            printf("\n");
    }
    return 1;
}
