#ifndef ROUND_QUEUE_H_INCLUDED
#define ROUND_QUEUE_H_INCLUDED


#include <stdio.h>
#include <stdlib.h>

#define QUEUE_MAX 100
typedef int QElemType;

typedef struct {
    QElemType *base;
    int head,tail;
}RoundQueue,*QueuePtr;

int initQueue(RoundQueue *Q);
int destoyQueue(RoundQueue *Q);
int clearQueue(RoundQueue *Q);

int isEmpty_Q(RoundQueue *Q);
int isFull_Q(RoundQueue *Q);
int QueueLength(RoundQueue *Q);
int getHead(RoundQueue *Q,QElemType *e);

int enQueue(RoundQueue *Q,QElemType e);
int deQueue(RoundQueue *Q,QElemType *e);
int QueueTraverse(RoundQueue *Q);



#endif // ROUND_QUEUE_H_INCLUDED
