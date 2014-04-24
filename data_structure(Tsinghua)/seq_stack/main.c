/*
test sequence stack!
*/

#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

int main()
{
    stack s;
    SElemType i,p;

    int num,base;     //used for conversion
    initStack(&s);
    for(i=30;i>=0;i--)
        push(&s,i);
    stackTraverse(s);
    getTop(s,&p);
    printf("\nThe top of stack is %d\n",p);
    printf("The length of stack is %d.\n",getLen(s));

    for(i=10;i>=0;i--)
        pop(&s,&p);
    stackTraverse(s);
    printf("The length of stack is %d.\n",getLen(s));
    clearStack(&s);
    printf("The length of stack is %d.\n",getLen(s));

    destroyStack(&s);

//Now test Parenthesis matching using stack


    match();
    return 0;          //avoid the following code to be executed!

// Now test conversion of "num" based on "base"

   printf("Please input two number for conversion:\n");
    while(scanf("%d%d",&num,&base))
        convert(num,base);



}
