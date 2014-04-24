/**

��Ŀ������һ���������飬�жϸ������ǲ���ĳ��Ԫ�������ĺ�������Ľ��������Ƿ��� true�����򷵻�false��

�������� 5��7��6��9��11��10��8��������һ�����������������ĺ�����������
      8
    /   \
   6    10
  / \   / \
 5  7  9  11

��˷��� true��

������� 7��4��6��5��û���Ŀ����ĺ�������Ľ����������У���˷���false��

    Done in 2014.4.5 by B.Y.sun

*/

#include <stdio.h>
#include <stdlib.h>

#define True 1
#define False 0
#define MAX_NUM 50

static int ispostorder(int arr[], int start, int end){
    int i=start;
    int left, right, middle;

    if(start>=end)
        return True;

    int test=arr[end];
    while(arr[i]<test && i<=end)
        i++;

    if(i>start)
        middle=i-1;
    else
        middle=start;

    for(;i<end;i++){
        if(arr[i]<test)
            return False;
    }

    left=ispostorder(arr, start, middle);
    right=ispostorder(arr, middle+1, end);
    return (left && right);
}

void test_postorder(int arr[], int start, int end){
    printf("Whether the input is PostorderTraversal?\t");
    if(ispostorder(arr, start, end))
        printf("True\n");
    else
        printf("False\n");
}

int main()
{
    int arr[MAX_NUM];
    int len,i=0;
    printf("Please enter the len of array : ");
    scanf("%d", &len);

    printf("Please enter the array with PostorderTraversal:\n");
    while(i<len){
        scanf("%d", &arr[i++]);
    }
    test_postorder(arr, 0, len-1);
    return 0;
}
