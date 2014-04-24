/**
    ��Ŀ������һ�Ŷ�Ԫ�����������°����ӡ����ÿ����㣬ͬһ���а��մ������ҵ�˳���ӡ��

    �����ܼ򵥣���һ��˵�����ǹ�ȱ�����ʹ��FIFO���б����ͺ��ˣ���д�´���ʵ��

    Done in 2014.4.6 by B.Y.sun
*/
#include <stdio.h>
#include <stdlib.h>

struct bnode{
    struct bnode *left,*right;
    int key;
};
int main()
{
    printf("Hello world!\n");
    return 0;
}

void level_traverse(struct bnode *head){
    ListQueue list;

    if(!root)
        return;

    initQueue(&list);
    enQueue(&list, head);
    printf("The tree with level traverse is:\n");
    while(!isEmpty(&list)){
        struct bnode *tmp;
        deQueue(&list, &tmp);
        printf("%d\t",tmp->key);
        if(tmp->left)
            enQueue(&list, tmp->left);
        if(tmp->right)
            enQueue(&list, tmp->right);
    }
}
