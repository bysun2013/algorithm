/**
使用面值分别为10、5、2、1的硬币，给出所有总面值为target的组合，并打印总数
*/

#include <iostream>

using namespace std;

const int COIN_NUM = 4;
int list[COIN_NUM] = {10, 5, 2, 1};
int coin[COIN_NUM] = {0};
int count = 0;
void solution(int target, int k)
{
    if(k == COIN_NUM - 1)
    {
        coin[k] += target;
        for(int i = 0; i < COIN_NUM; i++)
            cout << list[i] << ":" << coin[i] << "  ";
        cout << endl;
        count++;
        return;
    }

    for(int j = k+1; j < COIN_NUM; j++)
        coin[j] = 0;
    solution(target, k+1);

    while(target >= list[k])
    {
        coin[k]++;
        target -= list[k];
        for(int j = k+1; j < COIN_NUM; j++)
            coin[j] = 0;
        solution(target, k+1);
    }
}

int main()
{
    int target;
    cin >> target;
    solution(target, 0);

    cout << "Count: " << count << endl;
    return 0;
}
