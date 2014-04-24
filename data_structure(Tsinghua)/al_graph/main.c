#include <stdio.h>
#include <stdlib.h>

#include "al_graph.h"
int main()
{
    al_graph g;
    cs_tree t=NULL;
    creat_algraph(&g);
//    dfs_traverse_alghaph(&g,visit);
//    bfs_traverse_alghaph(&g,visit);
    printf("\nHello world!\n");

    dfs_forest(&g,&t);
    preorder_traverse_recursion(t,visit_forest);
    return 0;
}
