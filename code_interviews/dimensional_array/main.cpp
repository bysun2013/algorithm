#include <iostream>
#include <vector>

using namespace std;

bool find_array(vector<vector<int> > &a,  int number){
    int rows, column;
    rows = a.size();
    if(rows <=0)
        return false;
    column = a[0].size();
    if(column <=0)
        return false;

    int max_colume = column -1;
    int min_row = 0;
    int right_above;

    while(min_row < rows && max_colume >= 0){
        right_above = a[min_row][max_colume];
        if(right_above == number)
            return true;
        else if(right_above > number){
            --max_colume;
        }else{
            ++min_row;
        }
    }
    return false;
}

int main()
{
    int a[4][4] = {
        {1,2,8,9},
        {2,4,9,12},
        {4,7,10,13},
        {6,8,11,15},
    };
    vector<vector<int> > v;
    for(int i =0; i<4; i++)
        v.push_back(vector<int>(a[i], a[i] + 4));
    int num;
    while(cin >> num)
        cout << boolalpha << find_array(v, num) << endl;

    return 0;
}
