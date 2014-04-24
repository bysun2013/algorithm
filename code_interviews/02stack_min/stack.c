#include "stack.h"

int init_stack(stack *s){
    s->base=(SElemType *)malloc(STACK_INIT_SIZE*sizeof(SElemType));
    if(!s->base)
    	return 1;
    s->top=s->base;
    s->stacksize=STACK_INIT_SIZE;

    s->min=(min_stack *)malloc(sizeof(min_stack));
    s->min->base=(int *)malloc(STACK_INIT_SIZE*sizeof(int));
    if(!s->min->base)
    	return 1;
    s->min->top=s->min->base;
    s->min->stacksize=STACK_INIT_SIZE;

//    printf("\nA new stack with min stack has been established!\n");
    return 0;
}

int destroy_stack(stack *s){
    if(!s)
        return 0;
    if(s->min){
        free(s->min->base);
        free(s->min);
        s->min=NULL;
    }
    free(s->base);
    s->base=s->top=NULL;
    s->stacksize=0;
//    printf("\nThe stack has been destroyed!\n");
    return 0;
}
int clear_stack(stack *s){
    if(!s)
        return 0;
    s->top=s->base;
    s->min->top=s->min->base;
    return 0;
}

int getlen(stack s){
	return (s.top-s.base);
}
int is_empty(stack s){
	return s.base==s.top;
}
int is_full(stack s){
	return (s.top-s.base==s.stacksize);
}

int get_top(stack s,SElemType *e){
    if(s.base==s.top)
        return 0;
    *e=*(s.top-1);
    return 0;
}

/*
 * 下面这三个函数的实现才是该题目的重点！
 * */

int push(stack *s,SElemType n){
	int min_index=-1;
	if(s->min->top != s->min->base){
		min_index= *(s->min->top-1);
	}

    if(s->top-s->base>=s->stacksize)
    {
        s->base=(SElemType *)realloc(s->base,sizeof(SElemType)*(s->stacksize+STACK_INCREMNET));
        if(!s->base)
            return 0;
        s->top=s->base+s->stacksize;
        s->stacksize+=STACK_INCREMNET;
    }
    if(s->min->top-s->min->base>=s->min->stacksize)
    {
        s->min->base=(int *)realloc(s->min->base,sizeof(int)*(s->min->stacksize+STACK_INCREMNET));
        if(!s->min->base)
            return 0;
        s->min->top=s->min->base+s->min->stacksize;
        s->min->stacksize+=STACK_INCREMNET;
    }

	*s->top++=n;
	/* 如果2个数相等且都是最小值，则取先进栈的为最小值 */
	if(min_index== -1){
		*s->min->top++=0;
	}else if(*(s->base+min_index)>n)
		*s->min->top++=(s->top-s->base-1);

	return 0;
}
/*
 * @指针n指向的内存位置存储栈中的退栈元素
 * */
int pop(stack *s,SElemType *n){
	int min_index=-1;

    if(s->base==s->top)
        return 0;
	if(s->min->top != s->min->base){
		min_index= *(s->min->top-1);
	}else
		return 1;

    if(s->top-s->base-1 == min_index){
    	s->min->top--;
    }
	*n= *(--s->top);
	return 0;
}
/*
 * @指针n指向的内存位置存储栈中的最小值
 * @返回最小值的索引
 * */
int get_min(stack *s, SElemType *n){
	int min_index=-1;
	if(s->min->top != s->min->base){
		min_index= *(s->min->top-1);
	}
	*n=*(s->base+min_index);
	return min_index;
}
/*
 * 按进栈顺序输出
 * */
int stack_traverse(stack s){
    SElemType* e;
    int *min,i=0;
    if(s.top==s.base){
       printf("This stack is empty!");
       return 0;
    }

    e=s.base;
    min=s.min->base;

    printf("\nThe elements in stack is:\n");
    for(;e<s.top;e++,i++){
         printf("%d\t",*e);
         if(i%6==5)
            printf("\n");
    }
    i=0;
    printf("\nthe minimum elements in proper order is:\n");
    for(;min<s.min->top;min++,i++){
         printf("%d\t",*min);
         if(i%6==5)
            printf("\n");
    }
    return 0;
}
