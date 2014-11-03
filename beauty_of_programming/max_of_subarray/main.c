/**
* 求子数组的最大值，貌似在《剑指offer》中见过
*/
#include <stdio.h>
#include <stdlib.h>

int max_of_subarry(int arr[], int num, int* sub_max){
    int i, max_sum, sum = 0;

    if(num == 0 || !arr)
        return -1;

    max_sum = arr[0];
    for(i = 0; i < num; i++){
        sum += arr[i];
        if(sum < 0){
            sum = 0;
            continue;
        }

        if(sum > max_sum)
            max_sum = sum;
    }

    if(max_sum > 0) {
        *sub_max = max_sum;
        return 0;
    }

    max_sum = arr[0];
    for(i = 1; i < num; i++){
        sum = arr[i];
        if(sum > max_sum)
            max_sum = sum;
    }

    *sub_max = max_sum;
    return 0;
}

#define MAX_LEN 50
int main()
{
    int len = 0, max_sum = 0, i;
    int arr[MAX_LEN];
    int err = 0;

    printf("Please enter the length of array: ");
    scanf("%d", &len);
    printf("Pleae enter the array:\n");

    for(i=0;i < len;i++)
        scanf("%d", &arr[i]);

    err = max_of_subarry(arr, len, &max_sum);
    if(err < 0)
        return err;

    printf("The max sum of subarray is %d\n", max_sum);
    return err;
}
