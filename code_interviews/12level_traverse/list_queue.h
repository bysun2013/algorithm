#ifndef LIST_QUEUE_H_INCLUDED
#define LIST_QUEUE_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>

//#define QElemType int
#define QElemType struct bnode*

typedef struct Node{
        QElemType value;
        struct Node *next;
}QNode,*QueuePtr;

typedef struct list_queue{
    QueuePtr head,tail;
}ListQueue;

int initQueue(ListQueue *Q);
int destoyQueue(ListQueue *Q);
int clearQueue(ListQueue *Q);
int isEmpty(ListQueue *Q);
int QueueLength(ListQueue *Q);
int getHead(ListQueue *Q,QElemType *e);
int enQueue(ListQueue *Q,QElemType e);
int deQueue(ListQueue *Q,QElemType *e);
int QueueTrave(ListQueue *Q);

#endif // LIST_QUEUE_H_INCLUDED
