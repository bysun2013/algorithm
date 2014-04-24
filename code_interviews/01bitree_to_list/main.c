/**
    题目：输入一棵二元查找树，将该二元查找树转换成一个排序的双向链表。
    要求不能创建任何新的结点，只调整指针的指向。
    比如将二元查找树
                                           10
                                         /    \
                                       6       14
                                     /  \     /　 \
                                 　4     8  12 　  16

    转换成双向链表  4=6=8=10=12=14=16。

    Done in 2014.4.3 by B.Y.sun
 */

#include "bs_tree.h"

#define LEFT 1
#define RIGHT 2

bitree convert(bitree t,int flag);
bitree convert_inorder(bitree t);
int main(){
	bitree t,list;
	create_bitree(&t);
	printf("\nSuccess create binary tree!\n");
	printf("Success change binary tree to list!\n");
	printf("created list is:\n");
	//list=convert(t,RIGHT);
	list=convert_inorder(t);
	for(t=list;t;t=t->rchild)
		printf("%d ",t->data);
	printf("\n");
	return 0;
}

/*
 * 将该二元查找树转换成一个排序的双向链表（方法1）
 *
 * 	当flag=LEFT时，返回最右段结点的指针；
 * 	当flag=RIGHT时，返回最左段结点的指针；
 *
 * */
bitree convert(bitree t,int flag){

	struct bitnode *left=NULL,*right=NULL,*tmp;
	if(!t)
		return NULL;

	if(!t->lchild && !t->rchild)
		return t;

	if(t->lchild)
		left=convert(t->lchild,LEFT);
	if(t->rchild)
		right=convert(t->rchild,RIGHT);

	if(left)
		left->rchild=t;
	t->lchild=left;

	if(right)
		right->lchild=t;
	t->rchild=right;
	tmp=t;
	if(flag==LEFT){
		while(tmp->rchild)
			tmp=tmp->rchild;
	}
	else{
		while(tmp->lchild)
			tmp=tmp->lchild;
	}
	return tmp;
}

/*
 * 中序遍历将该二元查找树转换成一个排序的双向链表（方法2）
 * */
static bitree pre;

int visit(bitree b)
{
	if(!b)
		return 1;
	if(!pre)
		pre=b;
	else{
		b->lchild=pre;
		pre->rchild=b;
		pre=b;
	}
    return 0;
}

bitree convert_inorder(bitree t){
	bitree tmp=t;

	inorder_traverse_recursion(t,visit);

	while(tmp->lchild)
		tmp=tmp->lchild;
	return tmp;
}
