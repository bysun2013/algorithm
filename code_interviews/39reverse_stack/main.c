/**
    题目：用递归颠倒一个栈。
    例如输入栈{1, 2, 3, 4, 5}，1 在栈顶。颠倒之后的栈为{5, 4, 3, 2, 1}，5 处在
    栈顶。

    讨论：这个问题使用一个数组可以轻松解决，但是题目要求递归的方法，
    所以问题变得很没意思，使用一个数组要比使用递归更加省空间！
    这种使用递归的方法很难理解...

    Done in 2014.4.26 by B.Y.Sun
*/
#define MAX_NUM 100

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct stack{
    int data[MAX_NUM];
    int *top;
};

struct stack* stack_init(){
    struct stack *s;
    s=malloc(sizeof(struct stack));
    memset(s, sizeof(struct stack), 0);
    s->top=s->data;
    return s;
};

void destroy_stack(struct stack *s){
    free(s);
}
int push(struct stack *s, int data){
    if(!s)
        return -1;
    *(s->top)=data;
    s->top++;
    return 0;
}

int pop(struct stack *s, int *data){
    if(!s || s->top==s->data)
        return -1;
    *data=*(--s->top);
    return 0;
}

void print_stack(struct stack *s){
    int *t=s->top;
    printf("The stack is:\n");
    while(t!=s->data){
        printf("%d ",*(--t));
    }
    printf("\n");
}
static void add_to_base(struct stack *s, int data){
    int t;
    if(s->top==s->data)
        push(s, data);
    else{
        pop(s, &t);
        add_to_base(s, data);
        push(s, t);
    }
}
int reverse_stack(struct stack *s){
    if(s->top==s->data)
        return 0;
    int data,err=0;
    err=pop(s, &data);
    if(err<0){
        printf("POP error.\n");
        return err;
    }
    err=reverse_stack(s);
    if(err<0){
        printf("REVERSE error.\n");
        return err;
    }
    add_to_base(s, data);

    return err;
}



int main()
{
    struct stack *s;
    int i;
    s=stack_init();
    for(i=5;i>0;i--)
        push(s,i);
    print_stack(s);
    reverse_stack(s);
    print_stack(s);
    return 0;
}
