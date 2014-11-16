#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
	struct node *left, *right;
	int weight;
}*nodep;

typedef struct priority_queue{
	nodep nodes[2002];
	int size;
}prio_queue;
/**
 * minimum priority queue, used by huffman code
 */
static inline void swap(nodep a[], int i, int j)
{
	nodep tmp;

	tmp = a[i];
	a[i] = a[j];
	a[j] = tmp;
}

static int min_heapify(prio_queue *pq, int k)
{
	int n = pq->size;
	nodep *a = pq->nodes;

	while(k <= n){
		int tmp = k, left, right;
		left = 2*k;
		right = 2*k + 1;
		
		if(left <= n && a[left]->weight < a[k]->weight)
			tmp = left;
		if(right <= n && a[right]->weight < a[tmp]->weight)
			tmp = right;
		
		if(k != tmp){
			swap(a, k, tmp);
			k = tmp;
		}else
			break;
	}

	return 0;
}

static int build_min_heap(prio_queue *pq)
{
	int i;
	int n = pq->size;

	for(i=n/2;i>0;i--){
		min_heapify(pq, i);
	}

	return 0;
}

static nodep extract_min(prio_queue *pq)
{
	nodep *a = pq->nodes;
	nodep t = a[1];

	swap(a, 1, pq->size);
	pq->size--;
	min_heapify(pq, 1);

	return t;
}

static void heap_insert(prio_queue *pq, nodep k)
{
	int parent;
	int i = ++(pq->size);
	nodep *a = pq->nodes;
	a[i] = k;

	while(i > 1){
		parent = i/2;
		if(a[parent]->weight > a[i]->weight){
			swap(a, i, parent);
			i = parent;
		}else
			break;
	}
}

static int huffman(prio_queue *pq, int n)
{
	nodep t1, t2, t;

	pq->size = n;
	build_min_heap(pq);
	while(pq->size > 1){
		t1 = extract_min(pq);
		t2 = extract_min(pq);
		t = (nodep)malloc(sizeof(struct node));
		if(!t){
			printf("malloc node fails\n");
			return -1;
		}
		t->left = t1;
		t->right = t2;
		t->weight = t1->weight + t2->weight;
		heap_insert(pq, t);
	}

	return 0;
}

static void prio_free_node(nodep p)
{
	if(p->left)
		prio_free_node(p->left);
	if(p->right)
		prio_free_node(p->right);
	free(p);
}

static void prio_queue_free(prio_queue *pq)
{
	nodep p = pq->nodes[1];

	prio_free_node(p);
}

static int _cal_weight(nodep np)
{
	int sum;
	if(!np->right && !np->left)
		return 0;
	
	sum = np->weight;
	if(np->right)
		sum += _cal_weight(np->right);
	if(np->left)
		sum += _cal_weight(np->left);

	return sum;
}

static int cal_weight(prio_queue *pq)
{
	int sum = 0;
	nodep root = pq->nodes[1];

	if(root)
		sum = _cal_weight(root);

	return sum;
}

int main()
{
	prio_queue pq;
	int n;
	nodep *a = pq.nodes;

	while(scanf("%d", &n) != EOF && n){
		int i;
		for(i=1;i<=n;i++){
			a[i] = (nodep)malloc(sizeof(struct node));
			if(a[i] == NULL){
				printf("malloc node fails\n");
				return -1;
			}
			scanf("%d", &(a[i]->weight));
			a[i]->left = a[i]->right = NULL;
		}
		
		huffman(&pq, n);
		/* calculate weight of all nodes */
		printf("%d\n",cal_weight(&pq));
		prio_queue_free(&pq);
	}

	return 0;
}

