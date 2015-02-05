#include <stdio.h>
#include <stdlib.h>

typedef struct prio_queue{
	int a[1001];
	int size;
}pqueue;

static inline void swap(int a[], int m, int n)
{
	int tmp;

	tmp = a[m];
	a[m] = a[n];
	a[n] = tmp;
}

static int min_heapify(pqueue *pq, int k)
{
	int t = k;
	int size = pq->size;
	int *a = pq->a;

	while(t <= size){
		int min_index = t;
		int left, right;
		left = 2*t;
		right = 2*t + 1;

		if(left <= size && a[min_index] > a[left])
			min_index = left;
		
		if(right <= size && a[min_index] > a[right])
			min_index = right;

		if(min_index != t){
			swap(a, min_index, t);
			t = min_index;
		}else
			break;
	}

	return 0;
}

static int build_min_heap(pqueue *pq)
{
	int i;
	int n = pq->size;

	for(i=n/2;i>0;i--){
		min_heapify(pq, i);
	}

	return 0;
}

static int extract_min(pqueue *pq)
{
	int size = pq->size;
	int k = pq->a[1];
	
	swap(pq->a, 1, size);
	pq->size--;
	min_heapify(pq, 1);

	return k;
}

static void insert_pqueue(pqueue *pq, int k)
{
	int *a = pq->a;
	int i = ++pq->size;
	a[i] = k;
	
	while(i > 1){
		int p = i/2;
		if(a[i] < a[p]){
			swap(a, i, p);
			i = p;
		}else
			break;
	}
}

/*
 * it returns the weight of huffman code, does not build huffman tree
 * */
static int huffman(pqueue *pq)
{
	int weight = 0;
	int t1, t2;
	int p;

	build_min_heap(pq);
	while(pq->size > 1){
		t1 = extract_min(pq);
		t2 = extract_min(pq);
		p = t1 + t2;
		insert_pqueue(pq, p);
		weight += p;
	}

	return weight;
}


int main()
{
	pqueue pq;
	int n;
	int *a = pq.a;

	while(scanf("%d", &n) != EOF && n){
		int i, weight;
		for(i=1;i<=n;i++)
			scanf("%d", &(a[i]));
		
		pq.size = n;
		weight = huffman(&pq);
		/* calculate weight of all nodes */
		printf("%d\n",weight);
	}

	return 0;
}
