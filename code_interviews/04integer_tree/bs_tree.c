/*
 * bs_tree.c
 *
 *  Created on: Nov 30, 2013
 *      Author: bing
 *      Binary Search Tree
 */

#include "bs_tree.h"
#include <stdlib.h>

/**
 * 采用中序递归建立二叉树
 * 输入方式可优化为数组赋值
 * */
struct bitnode* create_bitree()
{
	TElemType ch;
	struct bitnode* t;
	printf("Please input integer: ");
    scanf("%d",&ch);

    if(ch==0){
        t=NULL;
        return 0;
    }
    else
    {
        t=(struct bitnode*)malloc(sizeof(struct bitnode));
        if(!t)
            return NULL;
        (t)->data=ch;
        t->lchild=create_bitree();
        t->rchild=create_bitree();
    }
    return t;

}

int inorder_traverse_recursion(struct bitnode* t,int (*visit)(struct bitnode* e))
{
    if(t)
    {
		inorder_traverse_recursion(t->lchild,visit);
		visit(t);
		inorder_traverse_recursion(t->rchild,visit);
    }
    return 0;
}

int visit(struct bitnode* e){
    printf("%d\t",e->data);
    return 0;
}
