/*
 quick sort
*/

#include <stdio.h>
#include <stdlib.h>

static void quick_sort(int a[], int start, int end)
{
	int i = start; 
	int j = end;
	int temp;

	if(start >= end)
		return;
	
	temp = a[start]; 
	while(i<j){
		while(a[j] >= temp && i<j)
			j--;
		if(i<j){
			a[i] = a[j];
			i++;
		}

		while(a[i] < temp && i<j)
			i++;
		if(i<j){
			a[j] = a[i];
			j--;
		}
	}
	
	a[i] = temp;

	quick_sort(a, start, i-1);
	quick_sort(a, i+1, end);
}

int main()
{
	int n;
	int a[100];

	while(scanf("%d",&n)!=EOF && n){
		int i;
		for(i=0;i<n;i++)
			scanf("%d", &a[i]);

		quick_sort(a, 0, n-1);

		for(i=0;i<n;i++)
			printf("%d ", a[i]);
		printf("\n");
	}
}
