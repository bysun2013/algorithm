/**
https://leetcode.com/problems/unique-paths/

A robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below).

The robot can only move either down or right at any point in time. The robot is trying to reach
the bottom-right corner of the grid (marked 'Finish' in the diagram below).

How many possible unique paths are there?
*/

#include <iostream>

using namespace std;

class Solution {
public:
    int uniquePaths(int m, int n) {
        if(m <= 0 || n <= 0)
            return 0;
        if(m == 1 && n == 1)
            return 1;

        int steps = m-1 + n-1;
        double *fact = new double[steps+1];
        fact[0] = fact[1] = 1;
        for(int i=2;i<=steps;i++)
            fact[i] = fact[i-1]*i;
        double t1 = fact[steps];
        double t2 = fact[m-1]*fact[n-1];
        int result = (t1/t2+0.5);

        delete [] fact;
        return result;
    }
};

int main()
{
    int m,n;
    cin >> m >> n;
    Solution s;

    cout << s.uniquePaths(m, n) << endl;
    return 0;
}
