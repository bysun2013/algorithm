/**
    题目：把一个数组最开始的若干个元素搬到数组的末尾，我们称之为数组的旋转。
    输入一个排好序的数组的一个旋转，输出旋转数组的最小元素。
    例如数组{3, 4, 5, 1, 2}为{1, 2, 3, 4, 5}的一个旋转，该数组的最小值为1。

    Done in 2014.4.27 by B.Y.Sun
*/
#include <stdio.h>
#include <stdlib.h>

int rotate_min(int arr[], int n){
    int big, small;
    big=0;small=n-1;

    if(arr[big]<arr[small])
        return big;

    int tmp;
    while(small!=big+1){
        tmp=(big+small)/2;

        if(arr[tmp]>=arr[big])
            big=tmp;
        if(arr[tmp]<=arr[small])
            small=tmp;
    }
    return small;
}

int main()
{
    int arr[]={3,4,5,1,1,2};
    int result=rotate_min(arr, 6);
    printf("The result is: %d\n", arr[result]);
    return 0;
}
