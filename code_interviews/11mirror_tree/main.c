/**
题目：输入一颗二元查找树，将该树转换为它的镜像，即在转换后的二元查找树中，左子树的结点都大于右子树的结点。

    用递归和循环两种方法完成树的镜像转换。

    Done in 2014.4.6 by B.Y.sun

    PS:以前写的stack真的是超级难用！此处凑合着用吧，不想重新写了...
*/

#include <stdio.h>
#include <stdlib.h>
#include "search_tree.h"
#include "stack.h"


/* 递归实现*/
int recursion_mirror_tree(struct bnode *root){
    struct bnode *n;
    if(!root)
        return 0;
    if(!(root->lchild || root->rchild)){
        return 0;
    }

    n=root->lchild;
    root->lchild=root->rchild;
    root->rchild=n;

    recursion_mirror_tree(root->lchild);
    recursion_mirror_tree(root->rchild);

    return 0;
}
/* 迭代实现，栈和队列两种方式都可以实现*/
int iteration_mirror_tree(struct bnode *root){
    stack s;
    struct bnode *tmp;

    if(!root)
        return 0;

    initStack(&s);
    push(&s, root);
    while(!isEmpty_S(s)){
        pop(&s, &tmp);
        if(!(tmp->lchild || tmp->rchild)){
           continue;
        }
        struct bnode *n;
        n=tmp->lchild;
        tmp->lchild=tmp->rchild;
        tmp->rchild=n;

        if(tmp->lchild){
            push(&s, tmp->lchild);
        }
        if(tmp->rchild){
            push(&s, tmp->rchild);
        }
    }
    return 0;
}
int main()
{
    struct bnode *root=NULL;
    create_tree(&root);
    printf("after sort binary search tree: \n");
    inorder_traverse_recursion(root,visit);

    iteration_mirror_tree(root);

    printf("\nafter reverse, binary search tree: \n");
    inorder_traverse_recursion(root,visit);
    return 0;
}
