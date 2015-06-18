#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int size = strs.size();
        string s;
        if(size == 0)
            return s;

        s = strs[0];
        for(int i = 1; i< size; i++)
            s = _longest_prefix(strs[i], s);

        return s;
    }
private:
    string _longest_prefix(string &s1, string &s2){
        int len1 = s1.size();
        int len2 = s2.size();
        int i =0, j =0;
        while(i < len1 && j < len2){
            if(s1[i] != s2[j])
                break;
                i++,j++;
        }

        return s1.substr(0,i);
    }
};

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
