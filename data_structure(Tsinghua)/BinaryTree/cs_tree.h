#ifndef CS_TREE_H_INCLUDED
#define CS_TREE_H_INCLUDED

#define ElemType char

typedef struct cs_node{
    ElemType data;
    struct cs_node *child,*sible;
}cs_node,*cs_tree;

int preorder_traverse_recursion(cs_tree t,int (*visit)(ElemType e));


#endif // CS_TREE_H_INCLUDED
