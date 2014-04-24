/**

	��Ŀ: ����һ��������һ�ö�Ԫ��, �����ĸ���㿪ʼ���·���һֱ��Ҷ��������������н���γ�һ��
	·��. ��ӡ����������������ȵ�����·��
	����:
        �������� 22 �����¶�Ԫ��
                 10
                /  \
               5   12
              /      \
             7        4

        ���ӡ������·����10, 12 ��10, 5, 7

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
