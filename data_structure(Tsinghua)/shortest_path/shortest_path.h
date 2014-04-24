/*
 * shortest_path.h
 *
 *  Created on: Mar 2, 2014
 *      Author: bing
 */

#ifndef SHORTEST_PATH_H_
#define SHORTEST_PATH_H_

#include <limits.h>

/* 定义邻接矩阵的大小*/
#define NUM 6

enum{
	false=0,
	true=1
};

/*	在此程序中，我们假设权值不存在负数的情况	*/
typedef struct am_graph{
	int weight[NUM][NUM];
	int node;
	int edge;
}*graph;

int Dijkstra(graph g, int v, int* dist, int* path);

void show_path(int* path, int v, int end);

#endif /* SHORTEST_PATH_H_ */
