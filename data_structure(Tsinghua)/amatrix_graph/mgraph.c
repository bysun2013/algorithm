#include <stdio.h>
#include "mgraph.h"

int creat_mgraph(mgraph *m){
    int vnum,anum;

//modify it erveytime!
    m->arcnum=anum;
    m->vexnum=vnum;

    for(i=0,ch='A';i<m->vexnum;i++,ch++){
        m->vexs[i]=ch;
    }
    for(i=0;i<m->vexnum;i++)
    for(j=0;j<m->vexnum;j++){
            m->arcnum[i][j]={INFINITY INT,NULL};
    }

    return 1;
}
