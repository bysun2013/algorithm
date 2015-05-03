/**
并查集
*/
#include <iostream>

using namespace std;

int find_set(int s[], int x)
{
    int r = x;
    while(s[r] != r)
        r = s[r];
    int i = x;
    while(i != r){
        int j = s[i];
        s[i] = r;
        i = j;
    }

    return r;
}

void union_set(int s[], int x, int y)
{
    int sx = find_set(s, x);
    int sy = find_set(s, y);

    if(sx < sy)
        s[sx] = sy;
    else
        s[sy] = sx;
}
const int max_person = 10000;
int set[max_person];
//·µ»ØÅóÓÑÈ¦µÄ¸öÊý
int friends(int n ,int m, int r[][2])
{
    for(int i = 1; i <= n; i++)
        set[i] = i;
    for(int j = 0; j < m; j++)
        union_set(set, r[j][0], r[j][1]);
    int count = 0;
    for(int i = 1; i <= n; i++){
        if(set[i] == i)
            count++;
    }

    return count;
}

int main()
{
    int r[3][2] ={
        {1,2},
        {3,2},
        {4,5},
    };

    cout << "Friends count is " << friends(5, 3, r) << endl;
    return 0;
}
