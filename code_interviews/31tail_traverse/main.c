/**
    ��Ŀ������һ�������ͷ��㣬��β��ͷ���������ÿ������ֵ

    Done in 2014.4.20 by B.Y.Sun

    PS:û�о���ʵ�ָó���
*/
#include <stdio.h>
#include <stdlib.h>

struct node{
    struct node* next;
    int data;
};


static void traverse(struct node *head){
    if(!head)
        return;
    traverse(head->next);
    printf("%d", head->data);
    return;
}

int main()
{
    struct node *head;
    traverse(head);
    return 0;
}
