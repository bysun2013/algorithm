#include <stdio.h>
#include <stdlib.h>

#include "BiThrTree.h"

int main()
{
    bithr_tree bt,thrt;
    creat_threadtree(&bt);
    inorder_traverse_recursion(bt,visit);
    inorder_threading(&thrt,bt);
    inorder_traverse_thr(thrt,visit);
    destroy_threadtree(thrt);
    return 0;
}
