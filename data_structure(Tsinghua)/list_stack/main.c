/*
test list stack!
*/

#include <stdio.h>
#include <stdlib.h>
#include "list_stack.h"

int main()
{
    stack t;
    stack *s=&t;
    int i,p;
    initStack(s);
    for(i=30;i>=0;i--)
        push(s,i);
    stackTraverse(s);
    getTop(s,&p);
    printf("\nThe top of stack is %d\n",p);
    printf("The length of stack is %d.\n",getLen(s));

    for(i=10;i>=0;i--)
        pop(s,&p);
    stackTraverse(s);
    printf("The length of stack is %d.\n",getLen(s));
    clearStack(s);
    printf("The length of stack is %d.\n",getLen(s));

    destroyStack(s);
    return 0;
}
