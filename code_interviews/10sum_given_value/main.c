/**
    ��Ŀ������һ���Ѿ�������������������һ�����֣��������в�����������ʹ�����ǵĺ�������������Ǹ����֡�
    Ҫ��ʱ�临�Ӷ���O(n)������ж�����ֵĺ͵�����������֣��������һ�Լ��ɡ�

    ������������1,2,4,7,11,15������15. ����4+11=15, ������4��11

    Done in 2014.4.6 by B.Y.sun
*/

#include <stdio.h>
#include <stdlib.h>
#define MAX_LEN 100

int given_sum(int arr[], int len, int expected, int result[]);

int main()
{
    int len, expected, ret=0;
    int i=0;
    int arr[MAX_LEN];
    int result[2];

    printf("Please enter the len of array: ");
    scanf("%d", &len);

    printf("Please enter the value of array:\n");

    while(i<len){
        scanf("%d", &arr[i]);
        i++;
    }
    printf("Please enter the expected sum: ");
    scanf("%d", &expected);
    ret=given_sum(arr, len, expected, result);
    if(ret){
        printf("There is no right num! Please try again!\n");
        return ret;
    }

    printf("The result is: %d, %d\n", arr[result[0]], arr[result[1]]);
    return ret;
}
/*
    @result ���ҵ���2���������鳤��Ϊ2
*/
int given_sum(int arr[], int len, int expected, int result[]){
    int i,j;
    i=0;
    j=len-1;
    while(i<j){
        int sum=arr[i]+arr[j];

        if(sum == expected){
            result[0]=i;
            result[1]=j;
            return 0;
        }else if(sum > expected){
            j--;
        }else
            i++;
    }

    return 1;
}
