#ifndef AL_GRAPH_H_INCLUDED
#define AL_GRAPH_H_INCLUDED

/*
*   Adjacency List for UnDirect Graph
*  If used for direct graph, then need two list like this,
*  named anti Adjacency List
*/
#include <stdio.h>
#include <stdlib.h>
#include "../round_queue/round_queue.h"
#include "../BinaryTree/cs_tree.h"

#define MAX_VERTEX_NUM 20
typedef char vertex_type;
typedef char info_type;

typedef struct arcnode{
    int adjvex;
    struct arcnode *nextarc;
    info_type *info;
}arcnode;

typedef struct {
    arcnode *first_arc;
    vertex_type data;
}vnode;

typedef struct{
    vnode vertices[MAX_VERTEX_NUM];
    int vexnum,arcnum;
}al_graph;


int creat_algraph(al_graph *g);
int first_adjvex(al_graph *g,int v);
int next_adjvex(al_graph *g,int v,int w);
vertex_type get_vex(al_graph *g,int i);
static void dfs(al_graph *g,int (*visit)(int),int v);
int dfs_traverse_alghaph(al_graph *g,int (*visit)(int v));
int bfs_traverse_alghaph(al_graph *g,int (*visit)(int v));

void dfs_forest(al_graph *g,cs_tree *t);
void dfs_tree(al_graph *g,int v,cs_tree t);
int visit(int v);
int visit_forest(ElemType v);
#endif // AL_GRAPH_H_INCLUDED
