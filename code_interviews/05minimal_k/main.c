/**
    题目：输入n个整数，输出其中最小的k个。

    例如输入1,2,3,4,5,6,7和8, 则最小的4个数字为1,2,3和4

    Done in 2014.4.4 by B.Y.sun
*/

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define LEFT(i) (2*i)
#define RIGHT(i) (2*i+1)

static void exchange(int arr[], int i, int j){
		int tmp;

		tmp=arr[i];
		arr[i]=arr[j];
		arr[j]=tmp;
}

static int max_heapify(int arr[], int i, int heap_size){
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


int minimal_k(int arr[], int len, int k){
    int *minimal;
    int* largest; /*最小的k个数里最大的数*/
    int i;

    if(len<k)
        return 1;

    minimal=(int *)malloc(sizeof(int)*(k+1));
    for(i=0;i<=k;i++){
        minimal[i]=INT_MAX;
    }
    largest=(minimal+1);
    for(i=0;i<len;i++){
        if(*minimal>arr[i]){
            *largest=arr[i];
            max_heapify(minimal, 1, k);
        }
    }
    for(i=1;i<=k;i++){
        printf("%d\t", minimal[i]);
    }
    return 0;
}

#define MAX_NUM 50

int main()
{
    int arr[MAX_NUM];
    int len, k, i=0;

    printf("Please enter the len for selection: ");
    scanf("%d", &len);

    printf("Please enter the number for selection:\n");
    while(i<len){
        scanf("%d",&arr[i]);
        i++;
    }

    printf("Please enter the number of minimum: ");
    scanf("%d", &k);

    printf("\nthe smallest %d num is:\n",k);
    minimal_k(arr, len, k);

    return 0;
}
