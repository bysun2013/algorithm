#include "amatrix_graph\mgraph.h"

struct{
    int adjtex;
    vrtype cost;
}closedge[MAX_VERTEX_NUM];

void mini_spantree(mgraph *m,int u){
    int i,k,counts=1;
    for(i=0;i<m->vexnum;i++){
        if(i!=u)
            closedge[i]={u,m->arcs[u][i]};
    }
    closedge[u]=0;

    for(i=1;i<m->vexnum;i++){
         int j;
        k=minimum(closedge);
        printf("%d:%c\t",k,m->vexs[k]);
        closedge[k]=0;
        counts++;
        for(j=0;j<m->vexnum;j++){
            if(closedge[j].cost>(m->arcs[k][j]).adj)
                closedge[j]=(m->arcs[k][j]).adj;
        }
    }
    printf("\nThe total count is %d",counts);
}
