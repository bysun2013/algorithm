/*
 * main.c
 *
 *  Created on: Mar 2, 2014
 *      Author: bing
 */

#include <stdio.h>
#include <stdlib.h>
#include "shortest_path.h"


int main(void) {
    int n,e;     //表示输入的顶点数和边数
    while(scanf("%d%d",&n,&e)&&e!=0)
    {
        int i,j;
        int s,t,w;      //表示存在一条边s->t,权值为w
        graph g=malloc(sizeof(struct am_graph));
        int v0;
        int *dist=(int *)malloc(sizeof(int)*n);
        int *path=(int *)malloc(sizeof(int)*n);
        for(i=0;i<NUM;i++)
            for(j=0;j<NUM;j++)
                g->weight[i][j]=0;
        g->node=n;
        g->edge=e;
        for(i=0;i<e;i++)
        {
            scanf("%d%d%d",&s,&t,&w);
            g->weight[s][t]=w;
        }
        scanf("%d", &v0);        //输入源顶点
        for(i=0;i<n;i++){
        	for(j=0;j<n;j++)
        		printf("%d\t",g->weight[i][j]);
        	printf("\n");
        }
        printf("\n");
        Dijkstra(g,v0,dist,path);
        for(i=0;i<n;i++)
        {
            if(i!=v0)
            {
            	printf("%d\t",dist[i]);
                show_path(path,v0,i);
            }
        }
    }
	return 0;
}
