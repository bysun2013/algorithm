#include <stdio.h>
#include <stdlib.h>
#include "list_queue.h"
int main()
{
    ListQueue Q;
    int i;
    QElemType tmp;
    initQueue(&Q);
    for(i=0;i<20;i++)
        enQueue(&Q,i);
    QueueTrave(&Q);

    for(i=0;i<10;i++)
        deQueue(&Q,&tmp);
    QueueTrave(&Q);
    printf("\nThe length of list queue is %d.\n",QueueLength(&Q));
    clearQueue(&Q);
    printf("The list queue is %d.\n",isEmpty(&Q));
    printf("\nThe length of list queue is %d.\n",QueueLength(&Q));

    destoyQueue(&Q);
    return 0;
}
