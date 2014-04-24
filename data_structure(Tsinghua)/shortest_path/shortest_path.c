/*
 ============================================================================
 Name        : shortest_path.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "shortest_path.h"

int Dijkstra(graph g, int v, int* dist, int* path){
	int i,j,k;
	int* visited=malloc(sizeof(int)*g->node);

	for(i=0;i<g->node;i++){
		if(i!=v && g->weight[v][i]>0){
			dist[i]=g->weight[v][i];
			path[i]=v;
		}else{
			dist[i]=INT_MAX;
			path[i]=-1;
		}
		visited[i]=false;
	}
	path[v]=v;
	dist[v]=0;
	visited[v]=true;

	for(i=0;i<g->node;i++){
		int min=INT_MAX, u;
		for(j=0;j<g->node;j++){
			if(visited[j]==false && dist[j]<min){
					min=dist[j];
					u=j;
			}
		}
		visited[u]=true;
		for(k=0;k<g->node;k++){
			if(g->weight[u][k]>0 && visited[k]==false)
				if(dist[k]>dist[u]+g->weight[u][k]){
					dist[k]=dist[u]+g->weight[u][k];
					path[k]=u;
				}
		}
	}
	return 0;
}

void show_path(int* path, int v, int end){
	int i=end;
	printf("%d ",end);
	while(i!=v){
		printf("<--%d ",path[i]);
		i=path[i];
	}
	printf("\n");
}
