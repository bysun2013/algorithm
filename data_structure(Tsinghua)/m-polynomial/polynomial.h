#ifndef POLYNOMIAL_H_INCLUDED
#define POLYNOMIAL_H_INCLUDED

/*
This program is used to practice m-polynomial(generalized list);
However,this is difficult to make it true,so I delayed it...
Hope one day I could make it!
*/

#include <stdio.h>

typedef enum{ATOM,LIST} ElemTag;

typedef struct MPNode{
    ElemTag tag;
    int exp;
    union{
        float coef;
        struct MPNode *hp;
    };
    struct MPNode *tp;
}*MPList;

int create_mp(MPList *mp);
int destroy_mp(MPList *mp);

int depth_mp(MPList *mp,int *depth);
int copy_mp(MPList *mp,MPList *ml);



#endif // POLYNOMIAL_H_INCLUDED
