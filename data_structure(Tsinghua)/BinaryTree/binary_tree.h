#ifndef BINARY_TREE_H_INCLUDED
#define BINARY_TREE_H_INCLUDED
/*
    All kinds of traverse including level traverse has been achieved!
*/
#include <stdio.h>
#include <stdlib.h>

#include "../seq_stack/stack.h"
#include "../round_queue/round_queue.h"

typedef char TElemType;
typedef struct bitnode{
    TElemType data;
    struct bitnode *lchild,*rchild;
}bitnode,*bitree;

int create_bitree(bitree *t);

int preorder_traverse_recursion(bitree t,int (*visit)(TElemType e));
int inorder_traverse_recursion(bitree t,int (*visit)(TElemType e));
int postorder_traverse_recursion(bitree t,int (*visit)(TElemType e));

int preorder_traverse(bitree t,int (*visit)(TElemType e));
int inorder_traverse(bitree t,int (*visit)(TElemType e));
int inorder_traverse_other(bitree t,int (*visit)(TElemType e));
int postorder_traverse(bitree t,int (*visit)(TElemType e));
int levelorder_traverse(bitree t,int (*visit)(TElemType e));
int visit(TElemType e);

#endif // BINARY_TREE_H_INCLUDED
