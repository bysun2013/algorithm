#include <stdio.h>
#include <stdlib.h>

#define MAX_NUM 50

void count_sort(int arr[], int sorted[], int len, int k){
    int i;
    int* count=malloc(sizeof(int)*(k+1));  /* include zero */
    for(i=0;i<=k;i++)
        count[i]=0;

    for(i=1;i<=len;i++){
        count[arr[i]]++;
    }
    for(i=1;i<=k;i++){
        count[i]=count[i]+count[i-1];
    }
    for(i=len;i>=1;i--){
        int m;
        m=count[arr[i]];
        sorted[m]=arr[i];
        count[arr[i]]--;
    }
    free(count);
}


int main(int argc, char *argv[]) {
	int i=0, j, num, size, range;
	int arr[MAX_NUM];
	int sorted[MAX_NUM];

	printf("range for count sort: ");
	scanf("%d",&range);

    printf("how many numbers of interger for count sort: ");
	scanf("%d",&size);

	printf("please enter %d interger for sort:\n", size);
	while(i<size){
        scanf("%d",&num);
		arr[++i]=num;
	}

	count_sort(arr, sorted, size, range);

    printf("\nbefore count sort:\n");
	for(j=1;j<=size;j++){
		printf("%d\t",arr[j]);
	}

	printf("\nafter count sort:\n");
	for(j=1;j<=size;j++){
		printf("%d\t",sorted[j]);
	}
	return 0;
}

