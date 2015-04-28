#include <iostream>

using namespace std;


void print_matrix_incircle(int *number, int row, int column, int start)
{
    int endy = column - start - 1;
    int endx = row - start -1;

    for(int i = start; i <= endy; i++){
        cout << *(number + column*start + i) << " ";
    }

    if(start < endx){
        for(int i = start + 1; i <= endx; i ++)
            cout << *(number + column*i + endy) << " ";
    }

    if(start < endx && endy > start){
        for(int i = endy -1; i >= start; i--)
            cout << *(number + column*endx + i) << " ";
    }
    if(start < endx && endy > start + 1){
        for(int i = endx - 1; i> start; i--)
            cout << *(number + column*i + start) << " ";
    }
}

void print_matrix_clock_wisely(int *number, int row, int column)
{
    if(!number || row <= 0 || column <= 0)
        return;
    int start = 0;
    while(2*start < row && 2*start < column){
        print_matrix_incircle(number, row, column, start);
        start++;
    }
}

int main()
{
    int a[3][5] = {
        {1, 2, 3, 4, 5},
        {6,7, 8, 9, 10},
        {11,12, 13,14,15},
    };

    print_matrix_clock_wisely((int *)a, 3, 5);
    cout  << endl;
    return 0;
}
