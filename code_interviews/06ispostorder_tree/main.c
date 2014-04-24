/**

题目：输入一个整数数组，判断该数组是不是某二元查找树的后序遍历的结果。如果是返回 true，否则返回false。

例如输入 5、7、6、9、11、10、8，由于这一整数序列是如下树的后序遍历结果：
      8
    /   \
   6    10
  / \   / \
 5  7  9  11

因此返回 true。

如果输入 7、4、6、5，没有哪棵树的后序遍历的结果是这个序列，因此返回false。

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
