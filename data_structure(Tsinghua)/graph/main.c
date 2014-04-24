#include <stdio.h>
#include <stdlib.h>
/*
**  怎么说呢，利用邻接双重表实现遍历，是一个很不明智的选择！
*   尝试使用简单的邻接表实现DFS和BFS
*/


#include "aml_graph.h"

int main()
{
    aml_graph g;
    create_udg_aml(&g);
    dfs_traverse_aml(&g,visit_aml);
    printf("Hello world!\n");
    return 0;
}
