/*
 * 给你n个点，m条无向边，每条边都有长度d和花费p，给你起点s终点t，
 * 要求输出起点到终点的最短距离及其花费，如果最短距离有多条路线，则输出花费最少的。
 * 
 * 输入：
 * 输入n,m，点的编号是1~n,然后是m行，每行4个数 a,b,d,p，表示a和b之间有一条边，且其长度为d，花费为p。
 * 最后一行是两个数 s,t;起点s，终点t。n和m为0时输入结束。
 * (1<n<=1000, 0<m<100000, s != t)
 * 
 * 输出：
 * 输出 一行有两个数， 最短距离及其花费。
 * 
 * */
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct edge{
	int s;
	int d;
	int length;
	int price;
	struct edge *next;
};

struct vertex{
	int length;
	int price;
	int pre;
	struct edge* edges;
};

struct graph{
	int v;
	int e;
	struct vertex* vertices;
};

static void relax(struct graph *g, struct edge *e){
	int s = e->s;
	int d = e->d;
	struct vertex *vertices = g->vertices;

	if(vertices[s].length == INT_MAX)
		return;

	if(vertices[d].length > vertices[s].length + e->length){
		vertices[d].length = vertices[s].length + e->length;
		vertices[d].price = vertices[s].price + e->price;
		vertices[d].pre = s;
	}else if(vertices[d].length == vertices[s].length + e->length){
		if(vertices[d].price > vertices[s].price + e->price){
			vertices[d].price = vertices[s].price + e->price;
			vertices[d].pre = s;
		}
	}
}

static void init_single_source(struct graph *g, int s)
{
	int i;
	struct edge *e;
	struct vertex *vt;

	for(i=1,vt=g->vertices;i<=g->v;i++){
		vt[i].length = vt[i].price = INT_MAX;
		vt[i].pre = 0;
	}

	g->vertices[s].length = g->vertices[s].price = 0;
}


static int bellman(struct graph *g, int s)
{
	int i, j;
	struct edge *e;
	struct vertex *vertices = g->vertices;

	init_single_source(g, s);

	for(i=1;i<g->v;i++){
		for(j=1;j<=g->v;j++){
			for(e=vertices[j].edges;e!=NULL;e=e->next){
				relax(g, e);
			}
		}
	}

	for(j=1;j<=g->v;j++){
		for(e=vertices[j].edges;e!=NULL;e=e->next){
			if(vertices[e->d].length > vertices[e->s].length + e->length)
				return 0;
		}
	}

	return 1;
}

static void add_edge(struct graph *g, int s, int d, int length, int price)
{
	struct edge *e;

	e = malloc(sizeof(struct edge));
	if(!e)
		printf("fail to malloc edge\n");
	e->length = length;
	e->price = price;
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
			scanf("%d%d%d%d", &a, &b, &d, &p);
			add_edge(&g, a, b, d, p);
			add_edge(&g, b, a, d, p);
		}

		scanf("%d%d", &source, &end);

		bellman(&g, source);
		
		printf("%d %d\n", g.vertices[end].length,g.vertices[end].price);
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

