#include <stdio.h>
#include <stdlib.h>
/*
**  ��ô˵�أ������ڽ�˫�ر�ʵ�ֱ�������һ���ܲ����ǵ�ѡ��
*   ����ʹ�ü򵥵��ڽӱ�ʵ��DFS��BFS
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
