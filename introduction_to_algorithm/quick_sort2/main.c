/*  this program is designed referring to introduction of algorithm,
    in my opinoin, it's not good compared to the previous one
*/

#include <stdio.h>
#include <stdlib.h>

#define MAX_NUM	 50

void exchange(int arr[], int i, int j){
		int tmp;

		tmp=arr[i];
		arr[i]=arr[j];
		arr[j]=tmp;
}

int partition(int arr[], int begin , int end){
    int x,i,j;
    i=begin-1;
    x=arr[end];
    for(j=begin;j<end;j++){
        if(arr[j]<x){
            i++;
            exchange(arr, i, j);
        }
    }
    exchange(arr, i+1, end);
    return i+1;
}

void quick_sort(int arr[], int begin, int end){
    if(begin<end){
       int q;
       q=partition(arr, begin, end);
       quick_sort(arr, begin, q-1);
       quick_sort(arr, q+1, end);
    }
}

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

	quick_sort(arr, 1, size);
	printf("after quick sort:\n");
	for(j=1;j<=size;j++){
		printf("%d\t",arr[j]);
	}
	return 0;
}
