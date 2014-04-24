#include <stdio.h>
#include <stdlib.h>

void swap(int arr[], int i, int j){
    int tmp;

    tmp=arr[i];
    arr[i]=arr[j];
    arr[j]=tmp;
}
void insert_sort(int arr[],int len){
    int i,j;
    for(i=2;i<=len;i++){
        j=i-1;
        while(arr[j+1]<arr[j] && j>0){
            swap(arr,j,j+1);
            j--;
        }
    }
}

#define MAX_NUM 50

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

	insert_sort(arr, size);

    printf("\nafter insert sort:\n");
	for(j=1;j<=size;j++){
		printf("%d\t",arr[j]);
	}

	return 0;
}
