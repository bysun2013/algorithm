/**
    ��Ŀ����һ�������ʼ�����ɸ�Ԫ�ذᵽ�����ĩβ�����ǳ�֮Ϊ�������ת��
    ����һ���ź���������һ����ת�������ת�������СԪ�ء�
    ��������{3, 4, 5, 1, 2}Ϊ{1, 2, 3, 4, 5}��һ����ת�����������СֵΪ1��

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
