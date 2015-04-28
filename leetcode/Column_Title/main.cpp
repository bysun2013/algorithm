/*
https://leetcode.com/problems/excel-sheet-column-title/
*/
#include <iostream>
#include <string>
#include <algorithm>
#include <stdexcept>

using namespace std;
const int ALPHABET_NUM = 26;
class Solution {
public:
    string convertToTitle(int n) {
        if(n < 0)
            throw logic_error("invalid argument");

        string s;
        int digit;
        while(n > 0){
            digit = (n-1) % ALPHABET_NUM;
            s += (digit+'A');
            n = (n-1)/ALPHABET_NUM;
        }

        reverse(s.begin(), s.end());
        return s;
    }
};

int main()
{
    Solution s;
    int n;

    while(cin >> n)
        cout << s.convertToTitle(n) << endl;

    cout << "Bye!" << endl;
    return 0;
}
