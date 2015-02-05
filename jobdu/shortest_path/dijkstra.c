#include <stdio.h>
#include <limits.h>
#include <stdlib.h>

struct vertex{
	int price;
	int length;
	struct edge *edges;
};

struct edge{
	struct edge *next;
	int price;
	int length;
	int s;
	int d;
};

typedef struct priority_queue{
	int *a;
	int size;
	struct vertex *vertices;
}*prio_queue;

struct graph{
	struct vertex *vertices;
	prio_queue pq;
	int v;
	int e;
};

static inline void swap(int a[], int n, int m){
	int tmp;
	
	tmp = a[n];
	a[n] = a[m];
	a[m] = tmp;
}

/*
 * priority queue
 * */
static void min_heapify(prio_queue pq, int i){
	struct vertex *vertices = pq->vertices;
	int *a = pq->a;
	int size = pq->size;
	int min = i, left = 2*i, right = 2*i+1;

	if(left <= size && vertices[a[left]].length < vertices[a[min]].length)
		min = left;
	if(right <= size && vertices[a[right]].length < vertices[a[min]].length)
		min = right;
	if(min != i){
		swap(a, min, i);
		min_heapify(pq, min);
	}
}

static void build_min_heap(prio_queue pq){
	int size = pq->size;
	int i;
	
	for(i=size/2;i>0;i--){
		min_heapify(pq, i);
	}
}

static struct vertex* extract_min(prio_queue pq){
	int *a = pq->a;
	int index = a[1];
	swap(a, 1, pq->size);
	pq->size--;
	
	min_heapify(pq, 1);
	
	return &(pq->vertices[index]);
}

static void decrease_key(prio_queue pq, int k){
	int *a = pq->a;
	struct vertex *vertices = pq->vertices;
	/* it's not good, but it's easy to implement */
	build_min_heap(pq);
}

static void init_single_source(struct graph *g, int s){
	int i;
	struct vertex *vertices = g->vertices;
	
	for(i=1;i<=g->v;i++)
		vertices[i].length = vertices[i].price = INT_MAX;

	vertices[s].length = vertices[s].price = 0;
}

static void relax(prio_queue pq, struct edge *e){
	int s = e->s;
	int d = e->d;
	struct vertex *vertices = pq->vertices;
	
	if(vertices[s].length == INT_MAX)
		return;
	if(vertices[d].length > vertices[s].length + e->length){
		vertices[d].length = vertices[s].length + e->length;
		vertices[d].price = vertices[s].price + e->price;

		decrease_key(pq, d);
	}else if(vertices[d].length == vertices[s].length + e->length){
		if(vertices[d].price > vertices[s].price + e->price)
			vertices[d].price = vertices[s].price + e->price;
	}
}

static int shortest_path(struct graph *g, int s){
	struct priority_queue pq;
	struct vertex *v;
	struct edge *e;
	int i;

	pq.vertices = g->vertices;
	pq.size = g->v;
	pq.a = malloc(sizeof(int)*(1+pq.size));

	for(i=1;i<=pq.size;i++)
		pq.a[i] = i;

	init_single_source(g, s);
	build_min_heap(&pq);

	while(pq.size){
		v = extract_min(&pq);
		for(e=v->edges;e!=NULL;e=e->next){
			relax(&pq, e);
		}
	}

	return 0;
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

		shortest_path(&g, source);
		
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

