#ifndef BITHRTREE_H_INCLUDED
#define BITHRTREE_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
enum point_tag {LINK,THREAD};
typedef int thr_elem_type;
typedef struct bithr_node{
    thr_elem_type data;
    struct bithr_node *lchild,*rchild;
    enum point_tag ltag,rtag;
}bithr_node,*bithr_tree;

int creat_threadtree(bithr_tree *t);
int destroy_threadtree(bithr_tree t);
int inorder_threading(bithr_tree *thrt,bithr_tree t);
void inthreading(bithr_tree p);

int inorder_traverse_recursion(bithr_tree t,int (*visit)(thr_elem_type e));
int inorder_traverse_thr(bithr_tree t,int (*visit)(thr_elem_type e));
int visit(thr_elem_type e);
#endif // BITHRTREE_H_INCLUDED
