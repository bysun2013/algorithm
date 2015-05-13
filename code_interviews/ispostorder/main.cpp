/*
题目24：
输入一个整数数组，判断该数组是不是某二叉搜索树的后序遍历的结果。
如果是则返回true，否则返回false。假设输入的数组的任意两个数字都互不相同
*/

#include <iostream>
#include <stdexcept>
#include <climits>

using namespace std;

bool ispostorder(int *a, int n)
{
    if(!a || n <= 0)
        return false;
    if(n == 1)
        return true;

    int root = a[n-1];
    int i = 0;
    while(i < n-1){
        if(a[i] > root)
            break;
        i++;
    }
    int middle = i;
    while(i < n-1){
        if(a[i] < root)
            return false;
        i++;
    }

    bool left = true, right = true;
    if(middle > 0)
        left = ispostorder(a, middle);

    if(middle < n-1)
        right = ispostorder(a+middle, n-middle-1);

    return (left && right);
}

int main()
{
    int a[] = {5,7,6,9,11,10,8};
    cout << boolalpha << ispostorder(a, 7) << endl;

    int a1[] = {7,4,6,5};
    cout << boolalpha << ispostorder(a1, 4) << endl;

    int a2[] = {1,2,3,4,5,6,7};
    cout << boolalpha << ispostorder(a2, 7) << endl;
    return 0;
}
