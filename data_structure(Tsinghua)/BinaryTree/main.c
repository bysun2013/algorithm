#include <stdio.h>
#include <stdlib.h>

#include "binary_tree.h"

int main()
{
    bitree t=NULL;
    create_bitree(&t);
    printf("The Root of this tree is %c.\n",t->data);

    printf("\nThe preorder of traverse is :\n");
    preorder_traverse_recursion(t,visit);

    printf("\nThe preorder of traverse without recursion is :\n");
    preorder_traverse(t,visit);

    printf("\nThe Inorder of traverse is :\n");
    inorder_traverse_recursion(t,visit);

    printf("\nThe Inorder of traverse without recursion is :\n");
    inorder_traverse(t,visit);

    printf("\nThe Another Inorder of traverse without recursion is :\n");
    inorder_traverse_other(t,visit);

    printf("\nThe postorder of traverse is :\n");
    postorder_traverse_recursion(t,visit);

    printf("\nThe postorder of traverse without recursion is :\n");
    postorder_traverse(t,visit);

    printf("\nThe levelorder of traverse without recursion is :\n");
    levelorder_traverse(t,visit);

    return 0;
}
