/**
    ��Ŀ��
        ���������������С�����һ�����б�ʾջ��push˳���ж���һ��������û�п����Ƕ�Ӧ��pop˳��
        ��Ϊ�˼���������Ǽ���push���е����������������ǲ���ȵģ�

    ���������push������1��2��3��4��5��
    ��ô4��5��3��2��1���п�����һ��popϵ�У�������4��3��5��1��2�Ͳ�������push���е�pop���С�

    Done in 2014.4.2

        PS: ����ǰд��stack����һ����ð�...
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
