#include <stdlib.h>
#include "array.h"

int InitArray(Array *A,int dim,...){
    int elemtotal=1,i;
    va_list ap;

    if(dim<1||dim>MAX_ARRAY_DIM)
        return 1;
    A->dim=dim;
    A->bounds=(int)malloc(dim*sizeof(int));
    if(!A->bounds) return 1;

    va_start(ap,dim);
    for(i=0;i<dim;i++){
        A->bounds[i]=va_arg(ap,int);
        if(A->bounds[i]<1) return 1;
        elemtotal*=A->bounds[i];
    }
    va_end(ap);

    A->base=(ElemType*)malloc(elemtotal*sizeof(ElemType));
    if(!A->base) return 1;

    A->constants=(int*)malloc(sizeof(int)*dim);
    if(!A->constants) return 1;
    A->constants[dim-1]=1;
    for(i=dim-2;i>=0;i--)
    A->constants[i]=A->constants[i+1]*A->bounds[i+1];
    return 0;
}
int DestroyArray(Array *A){
    if(A->constants){
        free(A->constants);
        A->constants=NULL;
    }
    if(A->bounds){
        free(A->bounds);
        A->bounds=NULL;
    }
    if(A->base){
        free(A->base);
        A->base=NULL;
    }
    return 0;
}

static int Locate(Array *A,va_list ap,int *off){
    int i,ind;
    *off=0;
    for(i=0;i<A->dim;i++){
        ind=va_arg(ap,int);
        if(ind<1||ind>=A->bounds[i])
            return -1;
        *off=*off+A->constants[i]*ind;
    }
    return 0;
}
int Value(Array A,ElemType *e,...){
    va_list ap;
    int result,off;
    ElemType *tmp;
    va_start(ap,e);
    if(result=Locate(&A,ap,&off)<0)
        return -1;
    *e=*(A.base+off);
    return 0;

}
int Assign(Array *A,ElemType e,...){
    va_list ap;
    int result,off;
    ElemType *tmp;
    va_start(ap,e);
    if(result=Locate(A,ap,&off)<0)
        return -1;
    *(A->base+off)=e;
    return 0;

}

int printArray(Array *A){
    int i,elemtotal;
    elemtotal=A->constants[0]*A->bounds[0];
    printf("\nThe Array is:\n");
    for(i=0;i<elemtotal;i++){
        printf("%d\t",*(A->base+i));
        if(i%10==9)
            printf("\n");
    }
    printf("\n");
    return 0;
}
