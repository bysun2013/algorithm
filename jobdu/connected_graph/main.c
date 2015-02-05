#include <stdio.h>
#include <stdlib.h>

enum color{WHITE, BLACK};
enum {false=0, true=1};

struct edge{
	int s;
	int d;
	struct edge *next;
};

struct vertex{
	struct edge *edges;
	enum color color;
};

struct graph{
	int v;
	int e;
	struct vertex *vertices;
};

static void dfs_visit(struct graph *g, int s){
	struct vertex *vertices = g->vertices;
	struct edge *e;
	
	vertices[s].color = BLACK;
	for(e=vertices[s].edges;e!=NULL;e=e->next){
		if(vertices[e->d].color != BLACK)
			dfs_visit(g, e->d);
	}
}

static int graph_connected(struct graph *g){
	int i, j;
	struct vertex *vertices = g->vertices;

	for(i=1;i<=g->v;i++)
		vertices[i].color = WHITE;

	dfs_visit(g, 1);

	for(i=2;i<=g->v;i++){
		if(vertices[i].color != BLACK)
			return false;
	}

	return true;
}

static void add_edge(struct graph *g, int s, int d)
{
	struct edge *e;

	e = malloc(sizeof(struct edge));
	if(!e)
		printf("fail to malloc edge\n");
	e->d = d;
	e->s = s;

	e->next = g->vertices[s].edges;
	g->vertices[s].edges = e;
}

int main()
{
	int n, m;

	while(scanf("%d%d", &n, &m) != EOF && (n || m)){
		int i;
		int a, b, d, p;
		int source, end;
		struct graph g;
		struct edge *e;

		g.v = n;
		g.e = m;
		g.vertices = calloc(n+1, sizeof(struct vertex));

		if(!g.vertices)
			return -1;

		for(i=0;i<m;i++){
			scanf("%d%d", &a, &b);
			add_edge(&g, a, b);
			add_edge(&g, b, a);
		}

		if(graph_connected(&g))
			printf("YES\n");
		else
			printf("NO\n");
		
		for(i=1;i<=n;i++){
			for(e=g.vertices[i].edges;e!=NULL;){
				struct edge *tmp;
				tmp = e->next;
				free(e);
				e = tmp;
			}
		}
		free(g.vertices);
	}
	
	return 0;
}

