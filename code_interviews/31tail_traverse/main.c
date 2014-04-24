/**
    题目：输入一个链表的头结点，从尾到头反过来输出每个结点的值

    Done in 2014.4.20 by B.Y.Sun

    PS:没有具体实现该程序
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
