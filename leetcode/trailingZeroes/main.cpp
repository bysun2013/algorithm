/*
https://leetcode.com/problems/factorial-trailing-zeroes/

Given an integer n, return the number of trailing zeroes in n!.

Note: Your solution should be in logarithmic time complexity.

*/
#include <iostream>

using namespace std;

class Solution {
public:
    int trailingZeroes(int n) {
        int sum = 0;
        //Be careful, long long is needed!
        for(long long base = 5; base <= n; base*=5)
            sum += n/base;
        return sum;
    }
};

int main()
{
    Solution s;
    int n;
    cin >> n;

    cout << s.trailingZeroes(n) << endl;
    return 0;
}
