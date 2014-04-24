/**
    题目：输入一颗二元树，从上往下按层打印树的每个结点，同一层中按照从左往右的顺序打印。

    这道题很简单，换一种说法就是广度遍历，使用FIFO队列遍历就好了，简单写下代码实现

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
