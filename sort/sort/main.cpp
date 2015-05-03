#include <iostream>

using namespace std;

/*********插入排序 ***********/
int insert_sort(int a[], int n)
{
    for(int i = 1; i < n;i++){
        if(a[i] < a[i-1]){
            int t = a[i];
            int j = i-1;
            while(j >= 0 && t < a[j]){
                a[j+1] = a[j];
                j--;
            }
            a[j+1] = t;
        }
    }

    return 0;
}

/*********希尔排序 ***********/
int shell_sort(int a[], int n)
{
    for(int gap = n/2; gap > 0; gap=gap/2){
        for(int i=gap;i<n;i++){
            if(a[i] < a[i - gap]){
                int t = a[i];
                int j = i - gap;
                while(j >= 0 && a[j] > t){
                    a[j + gap] = a[j];
                    j -= gap;
                }
                a[j+gap] = t;
            }
        }
    }

    return 0;
}

/*********冒泡排序 ***********/
int bubble_sort(int a[], int n)
{
    for(int i = n-1;i>=0;i--){
        bool need = false;
        for(int j = 0;j<i;j++){
            if(a[j] > a[j+1]){
                int tmp = a[j];
                a[j] = a[j+1];
                a[j+1] = tmp;
                need = true;
            }
        }
        if(need == false)
            break;
    }
    return 0;
}

/*********快速排序 ***********/
int partition(int a[], int low, int high)
{
    if(low >= high)
        return 0;

    int t = a[low];
    while(low < high){
        while(low < high && a[high] > t) high--;
        if(low < high)
            a[low++] = a[high];
        while(low < high && a[low] < t) low++;
        if(low < high)
            a[high--] = a[low];
    }
    a[low] = t;

    return low;
}

int quick_sort(int a[], int low, int high){

    if(low < high){
        int middle = partition(a, low, high);
        quick_sort(a, low, middle - 1);
        quick_sort(a, middle+1, high);
    }

    return 0;
}

/*********选择排序 ***********/
int select_sort(int a[], int n)
{
    for(int i=0;i<n-1;i++){
        int min = i;
        for(int j = i+1; j < n; j++){
            if(a[j] < a[min])
                min = j;
        }
        if(min != i){
            int tmp = a[i];
            a[i] = a[min];
            a[min] = tmp;
        }
    }

    return 0;
}

/*********堆排序 ***********/
void heapify_max(int a[], int n, int k)
{
    if(k <= n/2){
        int min = k;
        int left = 2*k;
        int right = 2*k + 1;
        if(left < n && a[left] > a[min])
            min = left;
        if(right < n && a[right] > a[min])
            min = right;
        if(min != k){
            int tmp = a[k];
            a[k] = a[min];
            a[min] = tmp;
            heapify_max(a, n, min);
        }
    }
}
int build_maxheap(int a[], int n)
{
    for(int i = n/2;i>0;i--){
        heapify_max(a, n, i);
    }

    return 0;
}
void swap(int a[], int m, int n)
{
    int tmp = a[m];
    a[m] = a[n];
    a[n] = tmp;
}
/***********************
a[]中的元素从1开始
***********************/
int heap_sort(int a[], int n)
{
    build_maxheap(a, n);
    for(int i = n; i > 1; i--){
        swap(a, 1, i);
        heapify_max(a, i-1, 1);
    }

    return 0;
}

/*********二路归并排序 ---空间复杂度为 O(n) ***********/
void merge(int a[], int low, int middle, int high)
{
    int *ptmp = new int[high - low + 1];

    int i = 0, j = low, k;
    while(j <= high){
        ptmp[i] = a[j];
        i++,j++;
    }

    for(i = 0, j = middle-low+1, k = low; i <= middle - low && j <= high - low; k++){
        if(ptmp[i] < ptmp[j]){
            a[k] = ptmp[i];
            i++;
        }else{
            a[k] = ptmp[j];
            j++;
        }
    }

    while(i <= middle - low) a[k++] = ptmp[i++];
    while(j <= high - low) a[k++] = ptmp[j++];
}

/*********二路归并排序 ***********/
int merge_sort(int a[], int n, int low, int high)
{
    if(low < high){
        int middle = (low + high)/2;
        merge_sort(a, n, low, middle);
        merge_sort(a, n, middle+1, high);
        merge(a, low, middle, high);
    }

    return 0;
}


/*********打印数组***********/
static void print_array(int a[], int n)
{
    for(int i = 0; i< n; i++)
        cout << a[i] << " ";
    cout << endl;
}

int main()
{
    int a[] = {-1,4,2,1,3,0};

    //insert_sort(a, 5);
    //print_array(a, 5);

    //shell_sort(a, 5);
    //print_array(a, 5);

    //bubble_sort(a, 5);
    //print_array(a, 5);

    //quick_sort(a, 0, 4);
    //print_array(a, 5);

    //select_sort(a, 5);
    //print_array(a, 5);

    //heap_sort(a, 5);
    //print_array(a, 6);

    merge_sort(a, 6, 0, 5);
    print_array(a, 6);
    return 0;
}
