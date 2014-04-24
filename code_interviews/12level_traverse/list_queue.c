#include "list_queue.h"

int initQueue(ListQueue *Q){
    Q->head=Q->tail=(QNode*)malloc(sizeof(QNode));
    if(!Q->head)
        return 1;
    Q->head->next=NULL;
    return 0;
}
int destoyQueue(ListQueue *Q){
    clearQueue(Q);
    free(Q->head);
    Q->head=Q->tail=NULL;
    return 0;
}
int clearQueue(ListQueue *Q){
    QNode *tmp;
    tmp=Q->head->next;
    while(tmp){
        Q->head->next=tmp->next;
        free(tmp);
        tmp=Q->head->next;
    }
    Q->tail=Q->head;
    return 0;
}
int isEmpty(ListQueue *Q){
    return Q->head==Q->tail;
}
int QueueLength(ListQueue *Q){
    QNode *tmp;
    int length=0;

    tmp=Q->head->next;
    while(tmp){
        length++;
        tmp=tmp->next;
    }
    return length;
}
int getHead(ListQueue *Q,QElemType *e){
    if(Q->head==Q->tail)
        return 1;
    *e=Q->head->next->value;
    return 0;
}
int enQueue(ListQueue *Q,QElemType e){
    QNode *nd=(QNode*)malloc(sizeof(QNode));
    if(!nd)
        return 1;
    nd->value=e;
    nd->next=NULL;
    Q->tail->next=nd;
    Q->tail=nd;
    return 0;
}
int deQueue(ListQueue *Q,QElemType *e){
    QNode * nd;
    if(!Q)
        return -1;
    if(Q->head==Q->tail)
        return 1;
    nd=Q->head->next;
    *e=nd->value;
    Q->head->next=nd->next;
    if(nd==Q->tail)
        Q->tail=Q->head;
    free(nd);
    return 0;
}

int QueueTrave(ListQueue *Q){
    QNode *tmp;

    tmp=Q->head->next;
    printf("The Queue is: \n");
    while(tmp){
        printf("%d\t",tmp->value);
        tmp=tmp->next;
    }
    printf("\n");
    return 0;
}
