#include "al_graph.h"

int creat_algraph(al_graph *g)
{
    int curse[6][2]= {{0,3},{0,1},{1,4},{1,2},{2,4},{2,3}};
    int i,anum=6,vnum=5;
    char ch;
    arcnode *an,*tmp;
    vnode *vn;
    g->arcnum=anum;
    g->vexnum=vnum;
    for(i=0,ch='A'; i<g->vexnum; i++,ch++)
    {
        (g->vertices[i]).data=ch;
        (g->vertices[i]).first_arc=NULL;
    }
    for(; i<MAX_VERTEX_NUM; i++) g->vertices[i].first_arc=NULL;
    for(i=0; i<g->arcnum; i++)
    {
        // this is the first part
        an=(arcnode *)malloc(sizeof(arcnode));
        if(!an) return 0;
        an->adjvex=curse[i][1];
        an->nextarc=NULL;
        vn=&(g->vertices[curse[i][0]]);
        if(vn->first_arc==NULL)
        {
            vn->first_arc=an;
//printf("%d link to %c on top\n",an->adjvex,g->vertices[curse[i][0]].data,(g->vertices[curse[i][0]].first_arc)->adjvex);
        }
        else
        {
            tmp=vn->first_arc;
            while(tmp&&tmp->nextarc) tmp=tmp->nextarc;
            tmp->nextarc=an;
//printf("%d link to %d after %d\n",an->adjvex,curse[i][0],tmp->adjvex);
        }


        //this is the other part

        an=(arcnode *)malloc(sizeof(arcnode));
        if(!an) return 0;
        an->adjvex=curse[i][0];
        an->nextarc=NULL;
        vn=&g->vertices[curse[i][1]];
        if(vn->first_arc==NULL)
        {
            vn->first_arc=an;
//printf("%d link to %c on top\n",an->adjvex,g->vertices[curse[i][1]].data);
        }
        else
        {
            tmp=vn->first_arc;
            while(tmp&&tmp->nextarc) tmp=tmp->nextarc;
            tmp->nextarc=an;
//printf("%d link to %d after %d\n",an->adjvex,curse[i][0],tmp->adjvex);
        }
    }
    for(i=0; i<g->vexnum; i++)
    {
        tmp=g->vertices[i].first_arc;
        while(tmp)
        {
            printf("%d\t",tmp->adjvex);
            tmp=tmp->nextarc;
        }
        printf("\n");
    }
    printf("-----------------------------------------------------");
    return 1;
}

int first_adjvex(al_graph *g,int v)
{
    arcnode *p=g->vertices[v].first_arc;
    return p->adjvex;
}
int next_adjvex(al_graph *g,int v,int w)
{
    arcnode *p=g->vertices[v].first_arc;
    while(p&&p->adjvex!=w)
        p=p->nextarc;
    if(!p||!p->nextarc)
        return -1;
    if(p->adjvex==w)
        return p->nextarc->adjvex;
    return -1;
}

vertex_type get_vex(al_graph *g,int i){
    return g->vertices[i].data;
}

static int visited[MAX_VERTEX_NUM];

static void dfs(al_graph *g,int (*visit)(int),int v)
{
    int w;
    visited[v]=1;
    visit(v);    // visit(g->vertices[v]->data);      show the content of vertice.
    for(w=first_adjvex(g,v); w>=0; w=next_adjvex(g,v,w))
        if(!visited[w]) dfs(g,visit,w);

}

int dfs_traverse_alghaph(al_graph *g,int (*visit)(int v))
{
    int i;
    for(i=0; i<g->vexnum; i++)
        visited[i]=0;
    printf("\nThe DFS is :\n");
    for(i=0; i<g->vexnum; i++)
        if(!visited[i]) dfs(g,visit,i);
    return 1;
}
int bfs_traverse_alghaph(al_graph *g,int (*visit)(int v))
{
    RoundQueue q;
    int i,v=0;
    initQueue(&q);

    for(i=0; i<g->vexnum; i++)
        visited[i]=0;
    printf("\nThe BFS is :\n");

    for(i=0; i<g->vexnum; i++)
        if(!visited[i])
        {
            visited[i]=1;
            visit(i);
            enQueue(&q,i);
            while(!isEmpty_Q(&q))
            {
                int w;
                deQueue(&q,&v);
                for(w=first_adjvex(g,v); w>=0; w=next_adjvex(g,v,w))
                    if(!visited[w])
                    {
                        visited[w]=1;
                        visit(w);
                        enQueue(&q,w);
                    }

            }
        }

    destoyQueue(&q);
    return 1;
}


static cs_tree q;
void dfs_forest(al_graph *g,cs_tree *t){
    int i;
    cs_tree p,sl;
    for(i=0; i<g->vexnum; i++)
        visited[i]=0;
    printf("\nThe DFSForest is :\n");
    for(i=0; i<g->vexnum; i++)
        if(!visited[i])
        {
            p=(cs_tree)malloc(sizeof(cs_node));
           // *p= {get_vex(g,i),NULL,NULL} ;
           p->data=get_vex(g,i);
           p->child=p->sible=NULL;
            if(!*t)
                *t=p;
            else
                sl->sible=p;
            sl=q=p;
            dfs_tree(g,i,p);
        }
}
void dfs_tree(al_graph *g,int v,cs_tree t)
{
    int w,first=1;
    cs_tree p;
    visited[v]=1;
    for(w=first_adjvex(g,v); w>=0; w=next_adjvex(g,v,w))
        if(!visited[w])
        {
            p=(cs_tree)malloc(sizeof(cs_node));
            // *p={get_vex(g,w),NULL,NULL};
            (p)->data=get_vex(g,w);
            (p)->child=(p)->sible=NULL;
            if(first)
            {
                t->child=p;
                first=0;
            }
            else
                q->sible=p;
            q=p;
            dfs_tree(g,w,p);
        }
}

int preorder_traverse_recursion(cs_tree t,int (*visit)(ElemType e))
{
    if(t)
    {
        if(visit(t->data))
            if(preorder_traverse_recursion(t->child,visit))
                if(preorder_traverse_recursion(t->sible,visit))
                    return 1;
        return 0;
    }
    else
        return 1;
}

int visit(int v)
{
    printf("%d\t",v);
    return 1;
}

int visit_forest(ElemType v)
{
    printf("%c\t",v);
    return 1;
}
