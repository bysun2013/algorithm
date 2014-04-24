/**

	题目: 输入一个整数和一棵二元树, 从树的根结点开始往下访问一直到叶结点所经过的所有结点形成一条
	路径. 打印出和与输入整数相等的所有路径
	例如:
        输入整数 22 和如下二元树
                 10
                /  \
               5   12
              /      \
             7        4

        则打印出两条路径：10, 12 和10, 5, 7

        Done in 2014.4.4 by B.Y.sun
*/

#include <stdio.h>
#include <stdlib.h>
#include "list_stack.h"
#include "bs_tree.h"

static stack s;


void find_path(struct bitnode* t, int expect_sum, int *sum){
    int tmp=0;

	if(!t)
		return;
	*sum=*sum+t->data;
	push(&s, t->data);

	if(*sum == expect_sum){
        print_stack(&s);
	}

    if(t->lchild){
        find_path(t->lchild, expect_sum, sum);
    }
    if(t->rchild){
        find_path(t->rchild, expect_sum, sum);
    }

    pop(&s,&tmp);
    *sum=*sum-t->data;
}

int main(int argc, char *argv[]) {
    int expect_sum;
    struct bitnode* t;
    int sum=0;

    printf("Please enter the expected sum: ");
    scanf("%d", &expect_sum);

	init_stack(&s);
	t=create_bitree();

	find_path(t, expect_sum, &sum);
	return 0;
}
