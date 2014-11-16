#include <stdio.h>
#include <stdlib.h>

/* bit swap bugs, if zero */
static inline void swap(int a[], int i, int j)
{
	int tmp;

	tmp = a[i];
	a[i] = a[j];
	a[j] = tmp;
}

static int max_heapify(int a[], int n, int i)
{
	int left, right;

	while(i <= n/2){
		int tmp = i;
		left = 2*i;
		right = 2*i + 1;

		if(left <=n && a[i] < a[left])
			tmp = left;
		/* it's necessary to check if right is below n */
		if(right <=n && a[tmp] < a[right])
			tmp = right;

		if(i != tmp){
			swap(a, i, tmp);
			i = tmp;
		}else
			break;
	}

	return 0;
}

static void build_heap(int a[], int n)
{
	int i;

	for(i=n/2;i>0;i--){
		max_heapify(a, n, i);
	}
}

static void heap_sort(int a[], int n)
{
	int i;

	build_heap(a, n);

	for(i=n;i>1;i--){
		swap(a, i, 1);
		max_heapify(a, i-1, 1);
	}
}

int main()
{
	int n;
	int a[100];

	while(scanf("%d",&n)!=EOF && n){
		int i;
		for(i=1;i<=n;i++)
			scanf("%d", &a[i]);

		heap_sort(a, n);

		for(i=1;i<=n;i++)
			printf("%d ", a[i]);
		printf("\n");
	}

	return 0;
}
