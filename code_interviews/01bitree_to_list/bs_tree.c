/*
 * bs_tree.c
 *
 *  Created on: Nov 30, 2013
 *      Author: bing
 *      Binary Search Tree
 */

#include "bs_tree.h"
#include <stdlib.h>

/*
 * 采用中序递归建立二叉树
 * 输入方式可优化为数组赋值
 * */
int create_bitree(bitree *t)
{
	TElemType ch;
	printf("请输入整数：");
    scanf("%d",&ch);

    if(ch==0){
        *t=NULL;
        return 0;
    }
    else
    {
        *t=(bitree)malloc(sizeof(bitnode));
        if(!*t)
            return -1;
        (*t)->data=ch;
        create_bitree(&(*t)->lchild);
        create_bitree(&(*t)->rchild);
    }
    return 0;

}

int inorder_traverse_recursion(bitree t,int (*visit)(bitree e))
{
    if(t)
    {
		inorder_traverse_recursion(t->lchild,visit);
		visit(t);
		inorder_traverse_recursion(t->rchild,visit);
		return 0;
    }
    return 1;
}

