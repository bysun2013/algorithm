#include <iostream>

using namespace std;

const int N = 13;
int d[N];
int v[N];
int n;

void dfs(int depth)
{
    if(depth >= n){
        for(int i = 0; i< n; i++)
            cout << d[i];
        cout << endl;
        return;
    }

    for(int i = 1; i <= n;i++){
        if(v[i] == 0){
            v[i] = 1;
            d[depth] = i;
            dfs(depth + 1);
            v[i] = 0;
        }
    }
}

int permutation(int n)
{
    for(int i = 1; i <= n; i++)
        v[i] = 0;

    dfs(0);
    return 0;
}

int main()
{
    cin >> n;
    permutation(n);
    return 0;
}
