#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
public:
    void reverseWords(string &s) {
        string s1;
        for(int i = s.length()-1;i >= 0;){
            while(s[i] == ' ' && i >= 0)
                i--;
            if(i < 0)
                break;
            if(!s1.empty()) s1.push_back(' ');
            string word;
            while(s[i] != ' ' && i >= 0)
                word.push_back(s[i--]);
            reverse(word.begin(), word.end());
            s1.append(word);
        }
        s = s1;
    }
};

int main()
{
    Solution solution;
    string s = "  the   sky   is   blue  ";

    solution.reverseWords(s);
    cout << s << endl;

    return 0;
}
