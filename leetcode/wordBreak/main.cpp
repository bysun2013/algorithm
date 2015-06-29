/*

https://leetcode.com/submissions/detail/30911861/

Given a string s and a dictionary of words dict, determine
if s can be segmented into a space-separated sequence of one or more dictionary words.

For example, given
s = "leetcode",
dict = ["leet", "code"].

Return true because "leetcode" can be segmented as "leet code".

*/
#include <iostream>
#include <string>
#include <unordered_set>

using namespace std;

class Solution {
public:
    bool wordBreak(string s, unordered_set<string>& wordDict) {
        int len = s.size();
        bool **memo = new bool * [len];
        for(int i = 0; i < len; i++)
            memo[i] = new bool [len];

        for(int i = 0; i < len;i++)
            for(int j = 0; j < len;j++)
                memo[i][j] = false;

        string sub;
        for(int i = 0; i < len; i++){
            for(int j = 0; j < len - i; j++){
                //memo[j][j+i]
                sub = s.substr(j, i+1);
                if(wordDict.find(sub) != wordDict.end())
                    memo[j][j+i] = true;
                else{
                    for(int k = j; k < j+i; k++){
                        if(memo[j][k] && memo[k+1][j+i]){
                            memo[j][j+i] = true;
                            break;
                        }
                    }
                }
            }
        }
       // show_memo(memo, len);
        return memo[0][len-1];
    }
private:
    void show_memo(bool **memo, int len){
        for(int i = 0; i < len;i++){
            for(int j = 0; j < len; j++)
                cout << memo[i][j] << " ";
            cout << endl;
        }
        cout << endl;
    }
};

int main()
{
    Solution s;
    string str = "abcd";

    unordered_set<string> us;
    us.insert("a");
    us.insert("b");
    us.insert("abc");
    us.insert("cd");

    cout << "The result is "  << s.wordBreak(str, us) << endl;

    return 0;
}
