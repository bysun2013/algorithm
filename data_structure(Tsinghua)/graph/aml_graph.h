/*
*  Adjacency Multilist for UnDirect Graph
*/
#ifndef AML_GRAPH_H_INCLUDED
#define AML_GRAPH_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTEX_NUM 20
typedef char vertex_type;
typedef char info_type;
//typedef enum{unvisited,visited} visit_if;

typedef struct edge_box{
//    visit_if mark;
    int i_vex,j_vex;
    struct edge_box *ilink,*jlink;
    info_type *info;
}edge_box;

typedef struct {
    edge_box *first_arc;
    vertex_type data;
}vexbox;

typedef struct{
    vexbox adjmullist[MAX_VERTEX_NUM];
    int vexnum,arcnum;
}aml_graph;

int create_udg_aml(aml_graph *g);
int destroy_udg_aml(aml_graph *g);

int locate_vex_aml(aml_graph *g,vertex_type u);
int get_vex_aml(aml_graph *g,int v);
int put_vex_aml(aml_graph *g,int v,vertex_type value);

int first_adjvex_aml(aml_graph *g,int v);
int next_adjvex_aml(aml_graph *g,int v,int w);

static void dfs(aml_graph *g,int (*visit)(int v),int v);

void dfs_traverse_aml(aml_graph *g,int (*visit)(int v));
void bfs_traverse_aml(aml_graph *g,int (*visit)(int v));
int visit_aml(int v);


#endif // AML_GRAPH_H_INCLUDED
