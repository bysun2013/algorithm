#include <stdio.h>
#include <stdlib.h>

#define LEFT(i) (2*i)
#define RIGHT(i) (2*i+1)
#define MAX_NUM	 100

void exchange(int arr[], int i, int j){
		int tmp;

		tmp=arr[i];
		arr[i]=arr[j];
		arr[j]=tmp;
}

int max_heapify(int arr[], int i, int heap_size){
	int l,r,largest;

	l=LEFT(i);
	r=RIGHT(i);

	if(l<=heap_size && arr[l]>arr[i])
		largest=l;
	else
		largest=i;

	if(r<=heap_size && arr[r]>arr[largest])
		largest=r;

	if(largest != i){
		exchange(arr, i, largest);
		max_heapify(arr, largest, heap_size);
	}
	return 0;
}

int build_max_heap(int arr[], int len, int* heap_size){
	int i;
	*heap_size=len;

	for(i=len/2;i>=1;i--){
		max_heapify(arr, i, *heap_size);
	}
	return 0;
}
/* len equal to the size of array minus 1, because arr[0] is exclused */
int heap_sort(int arr[], int len){
	int heap_size = 0;
	int i;

	build_max_heap(arr, len, &heap_size);
	for(i=len;i>1;i--){
		exchange(arr, i, 1);
		heap_size--;
		max_heapify(arr, 1, heap_size);
	}
	return 0;
}

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int main(int argc, char *argv[]) {
	int i=0, j, num, size;
	int arr[MAX_NUM];
	printf("how many numbers of interger for sort: ");
	scanf("%d",&size);
	printf("please enter %d interger for sort:\n", size);
	while(i<size){
        scanf("%d",&num);
		arr[++i]=num;
	}

	heap_sort(arr, size);
	printf("after quick sort:\n");
	for(j=1;j<=size;j++){
		printf("%d\t",arr[j]);
	}
	return 0;
}
