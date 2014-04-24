#include <stdio.h>
#include <stdlib.h>

/**
    题目：输入一个链表的头结点，反转该链表，并返回反转后链表的头结点。

    Done in 2014.4.2
*/
struct node{
    struct node* next;
    int data;
};

/**
    The data is input reverse order, so the input list is the same as the reversed list.
    Got it!
*/
struct node* create_list(){
    int len,input,i=0;
    struct node *new_node;
    struct node *head=NULL;

    printf("Please enter total len of list:\n");
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
/** 实现链表反转的2种方式，实现过程基本相同 */
struct node* reverse_list(struct node *head){
    struct node *pre, *post;
    if(!head)
        return NULL;
    pre=NULL;
    post=head->next;
    while(post !=NULL){
        head->next=pre;
        pre=head;
        head=post;
        post=post->next;
    }
    head->next=pre;
    return head;
}
struct node* reverse_list2(struct node *head){
    struct node *pre, *post;
    struct node *reversed_head;
    if(!head)
        return NULL;
    pre=NULL;
    while(head !=NULL){
        post=head->next;
        if(!post)
            reversed_head=head;
        head->next=pre;
        pre=head;
        head=post;
    }

    return reversed_head;
}

int print_list(struct node* head){
    while(head!=NULL){
        printf("%d\t",head->data);
        head=head->next;
    }
    return 0;
}
int main()
{
    struct node* head, *reversed_head;
    head=create_list();
    printf("The list is:\n");
    print_list(head);
    reversed_head=reverse_list(head);
    printf("\nThe reversed list is:\n");
    print_list(reversed_head);
    return 0;
}
