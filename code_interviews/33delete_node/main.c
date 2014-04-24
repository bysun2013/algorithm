/**
    题目：给定链表的头指针和一个结点指针，在O(1)时间删除该结点

    Done in 2014.4.20 by B.Y.Sun

    PS:考察对时间复杂度的认识，和对各种可能的情况考虑周全
*/
#include <stdio.h>
#include <stdlib.h>

struct node{
    struct node *next;
    int data;
};

int delete_node(struct node *head, struct node *to_delete){
    struct node *t;

    if(!head || !to_delete)
        return 1;

    if(head == to_delete){
        printf("Error when delete head.\n");
        return -1;
    }

    if(!to_delete->next){
        t=head;
        while(t->next !=to_delete){
            t=t->next;
        }
        free(to_delete);
        t->next=NULL;
        to_delete=NULL;
    }else{
        t=to_delete->next;
        to_delete->data=to_delete->next->data;
        to_delete->next=to_delete->next->next;
        free(t);
        t=NULL;
    }

    return 0;
}

int main()
{
    struct node *head, *to_delete;
    head=NULL;
    to_delete=NULL;
    delete_node(head, to_delete);
    return 0;
}
