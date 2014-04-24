#include <stdio.h>
#include <stdlib.h>


#define MAX_NUM 50

void bubble_sort(int arr[], int len);
void bubble_sort2(int arr[], int len);

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

	bubble_sort2(arr, size);

    printf("\nafter insert sort:\n");
	for(j=1;j<=size;j++){
		printf("%d\t",arr[j]);
	}



	return 0;
}

void swap(int arr[], int i, int j){
    int tmp;

    tmp=arr[i];
    arr[i]=arr[j];
    arr[j]=tmp;
}

void bubble_sort(int arr[], int len){
    int i,j;
    for(i=1;i<len;i++){
        for(j=1;j<=len-i;j++){
            if(arr[j]>arr[j+1])
                swap(arr, j, j+1);
        }
    }
}

void bubble_sort2(int arr[], int len){
    int i=len,j;
    int flag=1;
    while(flag){
        flag=0;
        i--;
        for(j=1;j<=i;j++){
            if(arr[j]>arr[j+1]){
                swap(arr, j, j+1);
                flag=1;
            }
        }
    }

}
