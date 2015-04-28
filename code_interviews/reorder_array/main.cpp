#include <iostream>

using namespace std;

void reorder(int a[], int n)
{
    if(a == NULL || n <= 0)
        return;

    int i = 0, j = -1;
    while(i < n){
        if(a[i] & 1 == 1){
            ++j;
            swap(a[i], a[j]);
        }
        ++i;
    }
}

int main()
{
    int a[] = {1,2, 3, 4,5};
    reorder(a, 5);

    for(int i = 0; i< 5; i++)
        cout << a[i] <<" ";
    cout << endl;

    return 0;
}
