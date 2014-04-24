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

struct bitnode{
    TElemType data;
    struct bitnode *lchild,*rchild;
};

struct bitnode* create_bitree();
int visit(struct bitnode* e);
int inorder_traverse_recursion(struct bitnode* t,int (*visit)(struct bitnode* e));

#endif /* BS_TREE_H_ */
