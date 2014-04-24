#ifndef ARRAY_H_INCLUDED
#define ARRAY_H_INCLUDED

#include <stdarg.h>
#include <stdio.h>

#define MAX_ARRAY_DIM 8

typedef int ElemType;
typedef struct {
    ElemType *base;
    int dim;
    int *bounds;
    int *constants;
}Array;

int InitArray(Array *A,int dim,...);
int DestroyArray(Array *A);
static int Locate(Array *A,va_list ap,int *off);
int Value(Array A,ElemType *e,...);
int Assign(Array *A,ElemType e,...);

int printArray(Array *A);



#endif // ARRAY_H_INCLUDED
