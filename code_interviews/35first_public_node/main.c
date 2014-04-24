/**
    题目：两个单向链表，找出它们的第一个公共结点。

    Done in 2014.4.24 by B.Y.Sun
*/
#include <stdio.h>
#include <stdlib.h>

struct list{
    int key;
    struct list *next;
};

struct list* first_public_node(struct list *h1, struct list *h2){
    struct list *s;
    int len1=0, len2=0;
    s=h1;
    while(s){
        s=s->next;
        len1++;
    }

    s=h2;
    while(s){
        s=s->next;
        len2++;
    }

    int off;
    if(len1>len2){
        off=(len1-len2);
        while(off){
            h1=h1->next;
            off--;
        }
    }else{
        off=(len2-len1);
        while(off){
            h2=h2->next;
            off--;
        }
    }
    while(h1&&h2){
        if(h1==h2)
            break;
        h1=h1->next;
        h2=h2->next;
    }
    if(!h1 || !h2){
        printf("There are NO public list node.\n");
        return NULL;
    }
    return h1;
}

int main()
{
    struct list *h1, *h2, *public_node;

    h1=h2=NULL;
    public_node = first_public_node(h1, h2);

    if(!public_node){
        printf("The public node is NULL.\n");
        return -1;
    }
    printf("The public node is: %d\n", public_node->key);
    return 0;
}
