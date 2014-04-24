#include "aml_graph.h"

#define ARC_NUM 6

int create_udg_aml(aml_graph *g){
    int anum=6,vnum=5;
    int i;
    int arc_data[ARC_NUM][2]={{0,1},{0,3},{2,1},{2,3},{4,1},{4,2}};
    edge_box *eb,*ec;
    char ch;
    (g)->arcnum=anum;
    (g)->vexnum=vnum;
    for(i=0,ch='A';i<MAX_VERTEX_NUM;i++,ch++){
        (g)->adjmullist[i].data=ch;
        (g)->adjmullist[i].first_arc=NULL;
    }

    for(i=0;i<ARC_NUM;i++){
        if(!(eb=(edge_box *)malloc(sizeof(edge_box))))
            return -1;
        eb->j_vex=arc_data[i][1];
        eb->i_vex=arc_data[i][0];
        eb->ilink=NULL; eb->jlink=NULL;
//        eb->mark=0;

        //link ilink to the corresponding node
        ec=(g)->adjmullist[eb->i_vex].first_arc;
        if(ec==NULL){
            ec=eb;
        }
        else{
            edge_box *pre; int dr;
            while(ec!=NULL){
                pre=ec;
                if(ec->i_vex==eb->i_vex) {ec=pre->ilink;dr=1;}
                if(ec->j_vex==eb->i_vex) {ec=pre->jlink;dr=2;}
            }
            if(dr==1) pre->ilink=eb;
            else pre->jlink=eb;
        }

        //link jlink to the corresponding node
        ec=(g)->adjmullist[eb->j_vex].first_arc;
        if(ec==NULL){
            ec=eb;
        }
        else{
            edge_box *pre; int dr;
            while(ec!=NULL){
                pre=ec;
                if(ec->i_vex==eb->j_vex) {ec=ec->ilink;dr=1;}
                if(ec->j_vex==eb->j_vex) {ec=ec->jlink;dr=2;}
            }
            if(dr==1) pre->ilink=eb;
            else pre->jlink=eb;
        }
    }
    return 1;

}

int destroy_udg_aml(aml_graph *g){
    return 1;
}

int locate_vex_aml(aml_graph *g,vertex_type u){
    return 1;
}
int get_vex_aml(aml_graph *g,int v){
    return 1;
}
int put_vex_aml(aml_graph *g,int v,vertex_type value){
    return 1;
}

int first_adjvex_aml(aml_graph *g,int v){
    edge_box *eg=(g->adjmullist[v]).first_arc;
    return eg->i_vex==v?eg->j_vex:eg->i_vex;
}
int next_adjvex_aml(aml_graph *g,int v,int w){
    edge_box *ec,*eb=g->adjmullist[v].first_arc;
    int dr=0;
    while(eb->i_vex!=w&&eb->j_vex!=w){
        ec=eb;
        if(ec->i_vex==v) {eb=ec->ilink; dr=1;}
        if(ec->j_vex==v) {eb=ec->jlink; dr=2;}
    }
    return dr==1?eb->i_vex:eb->j_vex;
}

static int visited[MAX_VERTEX_NUM];
void dfs_traverse_aml(aml_graph *g,int (*visit)(int v)){
    int i;
    for(i=0;i<g->vexnum;i++)
        visited[i]=0;
    for(i=0;i<g->vexnum;i++)
        if(!visited[i]) dfs(g,visit,i);
}
static void dfs(aml_graph *g,int (*visit)(int v),int v){
    int w;
    visited[v]=1; visit(v);
    for(w=first_adjvex_aml(g,v);w>=0;w=next_adjvex_aml(g,v,w))
        if(!visited[w]) dfs(g,visit,w);

}

void bfs_traverse_aml(aml_graph *g,int (*visit)(int v)){

}

int visit_aml(int v){
    printf("%d\t",v);
    return 1;
}
