#ifndef SEARCH_TREE_H_INCLUDED
#define SEARCH_TREE_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>

typedef int TElemType;

typedef struct bnode{
    TElemType key;
    struct bnode *lchild,*rchild;
    struct bnode *parent;
}bnode;

struct bnode* search_tree(struct bnode* x, int k);
struct bnode* iterative_search_tree(struct bnode* x, int k);
struct bnode* maximum_tree(struct bnode *root);
struct bnode* minimum_tree(struct bnode *root);
void insert_node(struct bnode **root, struct bnode *z);
int delete_node(struct bnode **root, struct bnode *z);
int inorder_traverse_recursion(struct bnode* t,int (*visit)(TElemType e));
int visit(TElemType e);
int create_tree(struct bnode **root);

#endif // SEARCH_TREE_H_INCLUDED
