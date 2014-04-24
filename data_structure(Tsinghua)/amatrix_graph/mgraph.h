#ifndef MGRAPH_H_INCLUDED
#define MGRAPH_H_INCLUDED

#define INFINITY INT_MAX
#define MAX_VERTEX_NUM 30

typedef int vrtype;
typedef char *infotype;
typedef char vertextype;
typedef struct{
    vrtype adj;
    infotype info;
}arcell;

typedef struct{
    vertextype vexs[MAX_VERTEX_NUM];
    arc_cell arcs[MAX_VERTEX_NUM][MAX_VERTEX_NUM];
    int vexnum,arcnum;
}mgraph;

int creat_mgraph(mgraph *m);
#endif // MGRAPH_H_INCLUDED
