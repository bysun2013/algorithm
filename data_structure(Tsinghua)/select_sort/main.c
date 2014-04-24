#include <stdio.h>
#include <stdlib.h>


#define MAX_NUM 50

void select_sort(int arr[], int len);

int main(int argc, char *argv[]) {

	int i=0, j, num, size;
	int arr[MAX_NUM];

    printf("how many numbers of interger for insert sort: ");
	scanf("%d",&size);

	printf("please enter %d interger for sort:\n", size);
	while(i<size){
        scanf("%d",&num);
		arr[++i]=num;
	}

	select_sort(arr, size);

    printf("\nafter insert sort:\n");
	for(j=1;j<=size;j++){
		printf("%d\t",arr[j]);
	}



	return 0;
}

static void swap(int arr[], int i, int j){
    int tmp;

    tmp=arr[i];
    arr[i]=arr[j];
    arr[j]=tmp;
}

static void swap2(int arr[], int i, int j){
    if(arr[i] != arr[j]){
        arr[i] ^=arr[j];
        arr[j] ^=arr[i];
        arr[i] ^=arr[j];
    }
}

void select_sort(int arr[], int len){
    int i,j;
    int min;
    for(i=1;i<len;i++){
        min=i;
        for(j=i+1;j<=len;j++){
            if(arr[j]<arr[min])
                min=j;
        }
        swap2(arr, min, i);
    }
}
