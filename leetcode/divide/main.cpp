/*
https://leetcode.com/submissions/detail/27913906/

Divide two integers without using multiplication, division and mod operator.

If it is overflow, return MAX_INT.

*/

#include <iostream>
#include <climits>

using namespace std;

class Solution {
public:
    int divide(int dividend, int divisor) {
        if(divisor == 0)
            return 0;
        if(dividend == INT_MIN && divisor == -1)
            return INT_MAX;

        bool is_positive = true;
        if((dividend < 0) ^ (divisor < 0))
            is_positive = false;

        long long dividend_l = dividend;
        long long divisor_l = divisor;
        long long cur;
        long long count = 1;

        if(dividend_l < 0)
            dividend_l = -1 * dividend_l;
        if(divisor_l < 0)
            divisor_l = -1 * divisor_l;
        cur = divisor_l;

        while(cur <= dividend_l){
            count <<= 1;
            cur <<= 1;
        }

        int result = 0;
        while(cur >= divisor_l){
            while(cur <= dividend_l){
                dividend_l -= cur;
                result += count;
            }
            count >>= 1;
            cur >>= 1;
        }

        if(is_positive)
            return result;
        else
            return -1*result;
    }
};

int main()
{
    int dividend = -1010369383;
    int divisor = -2147483648;

    Solution s;
    cout << s.divide(dividend, divisor) << endl;
    return 0;
}
