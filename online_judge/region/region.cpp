/**
    题目描述：
    给定一个数组，判断数组内是否存在一个连续区间，使其和恰好等于给定整数k。
    输入：
    输入包含多组测试用例，每组测试用例由一个整数n(1<=n<=10000)开头，代表数组的大小。
    接下去一行为n个整数，描述这个数组，整数绝对值不大于100。
    最后一行为一个整数k(大小在int范围内)。
    输出：
    对于每组测试用例，若存在这个连续区间，输出其开始和结束的位置，s，e(s <= e)。
    若存在多个符合条件的输出，则输出s较小的那个，若仍然存在多个，输出e较小的那个。
    若不存在，直接输出"No"。
*/

#include <stdio.h>
#include <iostream>
#include <string>
#include <string.h>
#include <algorithm>
#include <stdlib.h>
#include <math.h>
#include <vector>
#include <map>

using namespace std;
const int maxn = 10005;

map<int, vector<int> >mp;
int array[maxn];
int sum[maxn];
int n,k;

void solve(){
    int s,e;
    vector<int>v;
    vector<int>::iterator it;
    for(s = 1;s <= n;s++){
        e = sum[s-1] + k;
        if(mp.find(e) == mp.end())
            continue;
        v = mp[e];
        for(it = v.begin(); it < v.end();it++){
            if((*it) >= s){
                printf("%d %d\n",s,(*it));
                return;
            }
        }
    }
    puts("No");
}

int main(){
    while(scanf("%d",&n) != EOF){
        mp.clear();
        for(int i = 1;i <= n;i++){
            scanf("%d",&array[i]);
            sum[i] = sum[i-1] + array[i];
            mp[sum[i]].push_back(i);
        }
        scanf("%d",&k);
        solve();
    }
    return 0;
}
