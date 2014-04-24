/**
    题目：定义栈的数据结构，要求添加一个min函数，能够得到栈的最小元素。
    要求函数min、push以及pop的时间复杂度都是O(1)。

    分析：这是去年google的一道面试题。

    Done in 2014.4.3 by B.Y.sun
 */

#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

int main()
{
    stack s;
    SElemType i,p;

    init_stack(&s);
    for(i=20;i>10;i--)
        push(&s,i);
    for(i=1;i<=10;i++)
        push(&s,i);
    stack_traverse(s);
printf("\n\nbegin pop...\n");
    for(i=15;i>0;i--)
        pop(&s,&p);
    stack_traverse(s);

    destroy_stack(&s);

    return 0;
}
