#ifndef HSTRING_H_INCLUDED
#define HSTRING_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>

typedef struct{
    char *ch;
    int len;
}HString;

int HStrAssign(HString *s,char *c);
int GetLength(HString *s);
int EmptyHStr(HString *s);
int CmpHStr(HString *s,HString *t);
int ClearHStr(HString* s);
int ConcatHStr(HString *s,HString *t1,HString *t2);
int SubHStr(HString *sub,HString *s,int pos,int len);
int printHStr(HString *s);

//I write two index function, one is simple, and another use KMP
int IndexHStr(HString *s,HString *sub,int pos);

int KMPIndexHStr(HString *s,HString *sub,int pos);

#endif // HSTRING_H_INCLUDED
