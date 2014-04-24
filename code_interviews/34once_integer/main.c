/**
    题目：一个整型数组里除了两个数字之外，其他的数字都出现了两次。
    请写程序找出这两个只出现一次的数字。要求时间复杂度是O(n)，空间复杂度是O(1)。

    Done in 2014.4.24 by B.Y.Sun
*/
#include <stdio.h>
#include <stdlib.h>

int xor_array(int arr[], int n, int *result){
    int res;
    int i;

    if(!arr)
        return -1;
    res=arr[0];
    for(i=1;i<n;i++){
        res=res^arr[i];
    }
    *result=res;
    return 0;
}

int two_int(int arr[], int n, int result[]){
    int error=0;
    int and_int;
    int *intp1, *intp2;
    error=xor_array(arr, n, &and_int);
    if(error<0)
        return error;

    int i, bit;
    for(i=0;i<32;i++){
        int tmp;
        tmp=and_int & (1<<i);
        if(tmp)
            break;
    }
    if(i>=32){
        error=-1;
        printf("There are NOT two difference!\n");
        return error;
    }
    bit=i;
    intp1=malloc(sizeof(int)*n);
    intp2=malloc(sizeof(int)*n);

    int index1=0, index2=0;
    for(i=0;i<n;i++){
        if(arr[i] & (1<<bit)){
            intp1[index1++]=arr[i];
        }else{
            intp2[index2++]=arr[i];
        }
    }
    if((error=xor_array(intp1, index1, &result[0]))<0)
        return error;
    if((error=xor_array(intp2, index2, &result[1]))<0)
        return error;

    free(intp1);
    free(intp2);
    return error;
}

int main()
{
    int arr[]={1,3,4,6,4,18,1,6};
    int result[2];
    if(two_int(arr, 8, result)<0){
        printf("Error in execute.\n");
        return -1;
    }
    printf("The two integer is:  %d\t%d",result[0], result[1]);
    return 0;
}
