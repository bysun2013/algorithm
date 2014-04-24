/**
    题目：输入一个整数数组，调整数组中数字的顺序，
    使得所有奇数位于数组的前半部分，所有偶数位于数组的后半部分。
    要求时间复杂度为O(n)。

    DONE in 2014.4.20 by B.Y.Sun

*/
#include <stdio.h>
#include <stdlib.h>

int odd_even(int arr[], int n);

int main()
{
    int arr[]={1,2,3,4,5,6,7,8,9};
    int n=9;
    int i;
    odd_even(arr, n);
    printf("The result is:\n");
    for(i=0;i<n;i++)
        printf("%d\t", arr[i]);
    return 0;
}

int odd_even(int arr[], int n){
    int i=0,j=n-1;

    int tmp;
    while(i<j){
        while(i<j && arr[j]%2==0)
            j--;
        tmp=arr[j];
        while(i<j && arr[i]%2==1)
            i++;
        arr[j]=arr[i];
        arr[i]=tmp;
    }
    return 0;
}
