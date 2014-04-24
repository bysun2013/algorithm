/*
 * bs_tree.h
 *
 *  Created on: Nov 30, 2013
 *      Author: bing
 */

#ifndef BS_TREE_H_
#define BS_TREE_H_
#include <stdio.h>

typedef int TElemType;

typedef struct bitnode{
    TElemType data;
    struct bitnode *lchild,*rchild;
}bitnode,*bitree;

int create_bitree(bitree *t);
int inorder_traverse_recursion(bitree t,int (*visit)(bitree e));

#endif /* BS_TREE_H_ */
