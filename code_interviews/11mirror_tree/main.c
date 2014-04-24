/**
��Ŀ������һ�Ŷ�Ԫ��������������ת��Ϊ���ľ��񣬼���ת����Ķ�Ԫ�������У��������Ľ�㶼�����������Ľ�㡣

    �õݹ��ѭ�����ַ���������ľ���ת����

    Done in 2014.4.6 by B.Y.sun

    PS:��ǰд��stack����ǳ������ã��˴��պ����ðɣ���������д��...
*/

#include <stdio.h>
#include <stdlib.h>
#include "search_tree.h"
#include "stack.h"


/* �ݹ�ʵ��*/
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
/* ����ʵ�֣�ջ�Ͷ������ַ�ʽ������ʵ��*/
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
