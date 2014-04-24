#include <stdio.h>
#include <stdlib.h>
/**
    题目：输入一个单向链表，输出该链表中倒数第k个结点。
    链表的倒数第0个结点为链表的尾指针。
    链表结点定义如下：
    struct ListNode{
        int m_nKey;
        ListNode* m_pNext;
    };

    Done in 2014.4.5 by B.Y.sun
*/

struct node{
    struct node* next;
    int data;
};

/* The data is input reverse order, so the input list is the same as the reversed list. */
struct node* create_list(){
    int len,input,i=0;
    struct node *new_node;
    struct node *head=NULL;

    printf("Please enter total len of list: ");
    scanf("%d", &len);
    if(len<=0)
        return NULL;
    printf("Please enter integer for list:\n");
    while(i<len){
        scanf("%d",&input);
        new_node=(struct node*)malloc(sizeof(struct node));
        if(!new_node)
            return NULL;
        new_node->data=input;
        new_node->next=head;
        head=new_node;
        i++;
    }
    return head;
}

int print_list(struct node* head){
    while(head!=NULL){
        printf("%d\t",head->data);
        head=head->next;
    }
    return 0;
}

struct node* last_k(struct node* head, int k){
    struct node *post_k, *p;
    int i=k;
    post_k=p=head;
    while(p && i>0){
        p=p->next;
        i--;
    }
    if(!p)
        return NULL;
    while(p){
        p=p->next;
        post_k=post_k->next;
    }
    return post_k;
}
int main()
{
    int k;
    struct node *head, *post_k;

    head=create_list();
print_list(head);
    printf("\nPlease enter the value of k: ");
    scanf("%d",&k);
    post_k=last_k(head, k);

    printf("The value of the last k node is: %d",post_k->data);
    return 0;
}
