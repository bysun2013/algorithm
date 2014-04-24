#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_NUM 50

/**
    @num是一个radix进制的整数，该函数返回该整数的第d位
*/
int get_digit(int num, int radix, int d){
    int i,tmp=num;
    for(i=d;i>1;i--){
        tmp=tmp/radix;
    }
    tmp=tmp%radix;
    return tmp;
}
/**
    @d 按照第d位排序，最1位是最低位
    @k 排序中的数字的范围，即数组的进制
*/
void count_sort(int arr[], int sorted[], int len, int k, int d){
    int i,j,m;
    int digit;
    static int num;
    int* count=malloc(sizeof(int)*(k));  /* include zero */
    for(i=0;i<k;i++)
        count[i]=0;

    for(i=1;i<=len;i++){
        digit=get_digit(arr[i], k, d);
        count[digit]++;
    }
    for(i=1;i<k;i++){
        count[i]=count[i]+count[i-1];
    }
    for(i=len;i>=1;i--){
        digit=get_digit(arr[i], k, d);
        m=count[digit];
        sorted[m]=arr[i];
        count[digit]--;
    }
    printf("\n%d.after radix sort:\n",++num);
	for(j=1;j<=len;j++){
		printf("%d\t",sorted[j]);
	}
/* i don't know why error occured when free `count`, so i comment out it. */
//	free(count);


}

/**
    @d the highest digit in sorted array
    @radix the radix of sorted array, in general it's ten
*/
void radix_sort(int arr[], int len, int radix, int d){
    int i,j;
    int* sorted=malloc(sizeof(int)*len);
    int* tmp;
    for(i=1;i<=d;i++){
        count_sort(arr, sorted, len, radix, i);
        tmp=arr;
        arr=sorted;
        sorted=tmp;
    }

    printf("\nafter radix sort:\n");
	for(j=1;j<=len;j++){
		printf("%d\t",arr[j]);
	}

/**
    here because allocated memory is swapped,
    there is no clue which is the real memory

    free(sorted);
*/

}

int main(int argc, char *argv[]) {

	int i=0, j, num, size;
	int arr[MAX_NUM];

    printf("how many numbers of interger for radix sort: ");
	scanf("%d",&size);

	printf("please enter %d interger for sort:\n", size);
	while(i<size){
        scanf("%d",&num);
		arr[++i]=num;
	}

    printf("\nbefore radix sort:\n");
	for(j=1;j<=size;j++){
		printf("%d\t",arr[j]);
	}
    printf("\n");
	radix_sort(arr, size, 10, 3); /* 此处我们以十进制,三位数做测试 */

	return 0;
}

