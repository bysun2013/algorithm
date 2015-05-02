#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    string multiply(string num1, string num2) {
        string rt(num1.size()+num2.size(), '0');

        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());
        for(unsigned int i=0;i<num1.size();i++){
            for(unsigned int j=0;j<num2.size();j++){
                int t = rt[i+j]- '0' + (num1[i]-'0')*(num2[j]-'0');
                rt[i+j] = t%10+ '0';
                rt[i+j+1] += t/10;
                cout << " r " << rt[i+j]<< endl;
            }
        }


        reverse(rt.begin(), rt.end());
        size_t first = rt.find_first_not_of('0');
        return rt.substr(first);
    }
};

int main()
{
    Solution s;
    string num1, num2;
    cin >> num1 >> num2;
    while(num1 != "0"){
        string result = s.multiply(num1, num1);
        cout << "The result is " << result << endl;
        cin >> num1 >> num2;
    }

    return 0;
}
