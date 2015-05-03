/**
https://leetcode.com/problems/count-primes/

Description:

Count the number of prime numbers less than a non-negative number, n

*/
#include <iostream>

using namespace std;

class Solution {
public:
    int countPrimes(int n) {
        if(n<2)
            return 0;
        bool *num = new bool[n];
        for(int i = 0; i< n;i++)
            num[i] = true;
        num[0] = num[1] = false;
        int cur = 2;
        while(cur*cur < n){
            int j;
            for(j = cur*cur; j < n;j+=cur)
                if(num[j] == true)
                    num[j] = false;
            cur++;
            while(cur*cur < n && num[cur] == false)
                cur++;
        }
        int count = 0;
        for(int i = 2; i < n ;i++)
            if(num[i] == true){
//                cout << i << " ";
                count++;
            }

        return count;
    }
};

int main()
{
    Solution s;

    cout << s.countPrimes(50) << endl;
    return 0;
}
