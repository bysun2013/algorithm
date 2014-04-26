/**
    ��Ŀ���õݹ�ߵ�һ��ջ��
    ��������ջ{1, 2, 3, 4, 5}��1 ��ջ�����ߵ�֮���ջΪ{5, 4, 3, 2, 1}��5 ����
    ջ����

    ���ۣ��������ʹ��һ������������ɽ����������ĿҪ��ݹ�ķ�����
    ���������ú�û��˼��ʹ��һ������Ҫ��ʹ�õݹ����ʡ�ռ䣡
    ����ʹ�õݹ�ķ����������...

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
