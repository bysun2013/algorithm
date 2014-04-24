/*
*  Orthogonal List for Direct Graph
*/
#ifndef OL_GRAPH_H_INCLUDED
#define OL_GRAPH_H_INCLUDED

#define MAX_VERTEX_NUM 20
typedef int vertex_type;
typedef char * info_type;

typedef struct arcbox{
    int tailvex,headvex;
    struct arcbox *hlink,tlink;
    info_type *info;
}arcbox;

typedef struct{
    arcbox *first_in,*first_out;
    vertex_type data;
}vexnode;

typedef struct{
    vexnode xlist[MAX_VERTEX_NUM];
    int vexnum,aecnum;
}ol_graph;


#endif // OL_GRAPH_H_INCLUDED
