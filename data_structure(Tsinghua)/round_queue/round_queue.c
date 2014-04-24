#include "round_queue.h"

int initQueue(RoundQueue *Q){
    Q->base=(QElemType*)malloc(sizeof(QElemType)*QUEUE_MAX);
    if(!Q->base)
        return 1;
    Q->tail=Q->head=0;

    return 0;
}
int destoyQueue(RoundQueue *Q){
    if(!Q)
        return 1;
    free(Q->base);
    Q->head=Q->tail=0;
    return 0;
}
int clearQueue(RoundQueue *Q){
    if(!Q)
        return 1;
    Q->tail=Q->head=0;
    return 0;
}
int isEmpty_Q(RoundQueue *Q){
    return Q->head==Q->tail;
}
int isFull_Q(RoundQueue *Q){
    return (Q->tail+1+QUEUE_MAX)%QUEUE_MAX==Q->head;
}
int QueueLength(RoundQueue *Q){
    return (Q->tail-Q->head+QUEUE_MAX)%QUEUE_MAX;
}
int getHead(RoundQueue *Q,QElemType *e){
    if(isEmpty_Q(Q))
        return 0;
    *e=*(Q->base+Q->head);
    return 1;
}
int enQueue(RoundQueue *Q,QElemType e){
    if(isFull_Q(Q))
        return 1;
    *(Q->base+Q->tail)=e;
    Q->tail=(Q->tail+QUEUE_MAX+1)%QUEUE_MAX;
    return 0;
}
int deQueue(RoundQueue *Q,QElemType *e){
    if(isEmpty_Q(Q))
        return 1;
    *e=*(Q->base+Q->head);
    Q->head=(Q->head+1+QUEUE_MAX)%QUEUE_MAX;
    return 0;
}
int QueueTraverse(RoundQueue *Q){
    int len,i;
    QElemType e;
    if(!Q)
        return 1;
    len=QueueLength(Q);
    printf("The Queue is :\n");
    for(i=0;i<len;i++){
        e=*(Q->base+(Q->head+i)%QUEUE_MAX);
        printf("%d\t",e);
    }
    printf("\n");
    return 0;
}
