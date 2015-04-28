#include <iostream>
#include <stdexcept>

using namespace std;

int min_inorder(int *a, int low, int high);
/**
升序数组旋转后，查找最小数
使用二分查找
*/
int min_in_rotated_array(int a[], int n)
{
    if(a == NULL || n <= 0)
        throw runtime_error("invalid argument");

    int low = 0, high = n-1, middle = 0;

    while(a[low] >= a[high]){
        if(low + 1 == high){
            middle = high;
            break;
        }

        middle = (low+high)/2;

        if(a[low] == a[high] && a[middle] == a[low]){
            int ret = min_inorder(a, low, high);
            return ret;
        }

        if(a[middle] <= a[high])
            high = middle;
        else if(a[middle] >= a[low])
            low = middle;
    }
    return a[middle];
}

int min_inorder(int *a, int low, int high)
{
    if(a == NULL || low > high)
        throw runtime_error("invalid argument");

    cout << " use inorder search " <<endl;
    int min_num = a[low++];

    while(low <= high){
        if(min_num > a[low])
            min_num = a[low];
        low++;
    }
    return min_num;
}

int main()
{
    int a[] = {1};
    int min_num = min_in_rotated_array(NULL, 1);

    cout << "The mininum number is " << min_num << endl;
    return 0;
}
