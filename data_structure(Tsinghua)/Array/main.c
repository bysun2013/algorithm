#include <stdio.h>
#include <stdlib.h>

#include "array.h"

int main()
{
    Array a;
    ElemType e;
    int i,bound[3]={3,4,2};
    InitArray(&a,3,bound[0],bound[1],bound[2]);
    printArray(&a);

    for(i=0;i<bound[0]*bound[1]*bound[2];i++){
        *(a.base+i)=i;
    }
    printArray(&a);
    Value(a,&e,2,2,1);
    printf("\nThe array[%d][%d][%d] is %d.\n",bound[0],bound[1],bound[2],e);

    Assign(&a,75,2,2,1);
    printArray(&a);
    DestroyArray(&a);
    printf("Hello world!\n");
    return 0;
}
