/**
    题目：输入一棵二元树的根结点，求该树的深度。
    从根结点到叶结点依次经过的结点（含根、叶结点）
    形成树的一条路径，最长路径的长度为树的深度。
    例如：
    输入二元树：
         10
        / \
       6  14
      /   / \
     4   12  16

    输出该树的深度: 3

    Done in 2014.4.14 by B.Y.Sun
*/
#include <stdio.h>
#include <stdlib.h>

typedef int TElemType;
typedef struct bitnode
{
    TElemType data;
    struct bitnode *lchild,*rchild;
} bitnode,*bitree;

int create_bitree(bitree *t)
{
    TElemType ch;

    printf("Please enter integer: (0 means NULL)\n");
    scanf("%d",&ch);

    if(ch==0)
        *t=NULL;
    else
    {
        *t=(bitree)malloc(sizeof(bitnode));
        if(!*t)
            return 0;
        (*t)->data=ch;
        create_bitree(&(*t)->lchild);
        create_bitree(&(*t)->rchild);
    }
    return 1;
}

int inorder_traverse_recursion(bitree t,int (*visit)(TElemType e))
{
    if(t)
    {
        if(inorder_traverse_recursion(t->lchild,visit))
            if(visit(t->data))
                if(inorder_traverse_recursion(t->rchild,visit))
                    return 1;
        return 0;
    }
    else
        return 1;
}

int visit(TElemType e)
{
    printf("%d ",e);
    return 1;
}

int depth_tree(struct bitnode * root)
{
    int depth_left, depth_right;

    if(!root)
        return 0;

    depth_left=depth_tree(root->lchild);
    depth_right=depth_tree(root->rchild);

    return (depth_left>depth_right)? (depth_left+1):(depth_right+1);
}

int main()
{
    bitree t=NULL;
    int depth;
    create_bitree(&t);

    printf("\nThe Inorder of traverse is :\n");
    inorder_traverse_recursion(t,visit);

    depth=depth_tree(t);

    printf("\nThe depth of tree is: %d\n", depth);

    return 0;
}
