#include "stack.h"

int convert(int num,int base){
    stack s;
    int N,n;
    N=num;
    initStack(&s);

    while(N){
        push(&s,N%base);
        N=N/base;
    }

    printf("The number after converted based on %d is:\n",base);
    while(!isEmpty(s)){
        pop(&s,&n);
        printf("%d",n);
    }
    printf("\n");
    return 0;
}
