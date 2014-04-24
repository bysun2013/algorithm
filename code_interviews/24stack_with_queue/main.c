/**
    题目：
        输入两个整数序列。其中一个序列表示栈的push顺序，判断另一个序列有没有可能是对应的pop顺序
        （为了简单起见，我们假设push序列的任意两个整数都是不相等的）

    比如输入的push序列是1、2、3、4、5，
    那么4、5、3、2、1就有可能是一个pop系列，但序列4、3、5、1、2就不可能是push序列的pop序列。

    Done in 2014.4.2

        PS: 我以前写的stack不是一般的烂啊...
*/

#include <stdio.h>
#include <stdlib.h>
#include "seq_stack\stack.h"

#define MAX_LEN 50

int is_possible_pop(const int push[], const int pop[], int len);

int main()
{
    int push[MAX_LEN];
    int pop[MAX_LEN];
    int len;
    int i=0;

    printf("Please enter total num of stack: ");
    scanf("%d",&len);

    printf("Please enter %d integer of push stack:\n", len);
    while(i<len){
        scanf("%d",&push[i++]);
    }

    i=0;
    printf("Please enter %d integer of pop stack:\n", len);
    while(i<len){
        scanf("%d",&pop[i++]);
    }

    printf("The result is: ");
    is_possible_pop(push, pop, len);

    return 0;
}

int is_possible_pop(const int push_a[], const int pop_a[], int len){
    stack s;
    int i=0, e=0, j=0;
    initStack(&s);

    if(push_a==NULL || pop_a==NULL || len<=0)
        return 1;

    for(;i<len;i++){
        while(!getTop(s, &e) || e!=pop_a[i]){
            if(j>=len)
                break;
            push(&s, push_a[j++]);
        }
        getTop(s, &e);
        if(e!=pop_a[i])
            break;
        pop(&s, &e);
    }
    if(!isEmpty_S(s)){
        printf("False\n");
        return 1;
    }
    printf("True\n");
    return 0;
}
