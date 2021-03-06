#include "list_stack.h"

int init_stack(stack *s){
    s->stacksize=0;
    s->base=s->top=(node)malloc(sizeof(node));
    if(!s->base)
        return 0;
    return 1;
}
int destroy_stack(stack *s){
    node temp;
    while(s->top!=s->base){
        temp=s->top->next;
        free(s->top);
        s->top=temp;
    }
    free(s->base);
    s->base=s->top=NULL;
    s->stacksize=0;
    return 0;
}
int clear_stack(stack *s){
    node temp;
    while(s->top!=s->base){
        temp=s->top->next;
        free(s->top);
        s->top=temp;
    }
    s->top=s->base;
    s->stacksize=0;
    return 0;
}

int getlen(stack *s){
    int len=0;
    node temp=s->top;
    if(s->base==NULL&&s->top==NULL)
        return -1;
    while(temp!=s->base){
        len++;
        temp=temp->next;
    }
    return len;
}
int isempty(stack *s){
    if(s->top==NULL)
        return -1;
    return (s->base==s->top);
}
int isfull(stack *s){
    return 0;
}

int gettop(stack *s,SElemType *e){
     if(s->top==NULL)
        return 1;
    *e=s->top->value;
    return 0;
}
int push(stack *s,SElemType n){
    node nd=(node)malloc(sizeof(node));
    if(!nd)
        return 1;
    nd->value=n;
    nd->next=s->top;
    s->top=nd;
    s->stacksize++;
    return 0;
}
int pop(stack *s,SElemType *n){
    node nd;
    if(!s->base)
        return 1;
    *n=s->top->value;
    nd=s->top;
    s->top=nd->next;
    free(nd);
    s->stacksize--;
    return 0;
}

int print_stack(stack *s){
    node temp;
    temp=s->top;
     if(!s->top)
        return 1;
    printf("\nThe stack in reversed order is:\n");
    while(temp!=s->base){
        printf("%d\t",temp->value);
        temp=temp->next;
    }
    printf("\n");
    return 0;
}
