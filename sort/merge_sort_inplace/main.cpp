/**
    ��·�鲢����
    �ռ临�Ӷ�Ϊ O(1)
*/
#include <iostream>

using namespace std;

void swap(int a[], int m, int n)
{
    int tmp = a[m];
    a[m] = a[n];
    a[n] = tmp;
}

/*********��ӡ����***********/
static void print_array(int a[], int n)
{
    for(int i = 0; i< n; i++)
        cout << a[i] << " ";
    cout << endl;
}

/***************** ԭ�غϲ�  ********************/
static void reverse_array(int a[], int start, int end)
{
    while(start < end){
        swap(a, start, end);
        start++, end--;
    }
}

/**  ����ѭ���ƶ�i��λ��*/
static void exchange(int a[], int start, int end, int middle)
{
    reverse_array(a, start, middle-1);
    reverse_array(a, middle, end);
    reverse_array(a, start, end);
}

/** ���ǲ���... */
void merge_inplace(int a[], int low, int middle, int high)
{
    int i = low, j = middle, k = high;

    while(i < j && j <= k){
        int step = 0;
        while(i < j && a[i] <= a[j])
            i++;
        while(j <= k && a[j] <= a[i]){
            j++;
            step++;
        }

        exchange(a, i, j-1, j-step);
        i += step;
    }
}

/*********��·�鲢���� ***********/
int merge_sort(int a[], int n, int low, int high)
{
    if(low < high){
        int middle = (low + high)/2;
        merge_sort(a, n, low, middle);
        merge_sort(a, n, middle+1, high);
        merge_inplace(a, low, middle+1, high);

//        cout << "low = " << low << ",high = " << high << ", middile= " << middle << endl;
//        print_array(a, n);
    }

    return 0;
}

int main()
{
    int a[] = {5,4,2,1,3,0};

    merge_sort(a, 6, 0, 5);
    print_array(a, 6);
    return 0;
}
