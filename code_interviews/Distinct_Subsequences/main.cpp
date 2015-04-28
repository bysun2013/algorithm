/*
https://leetcode.com/problems/distinct-subsequences/

Given a string S and a string T, count the number of distinct subsequences of T in S.

A subsequence of a string is a new string which is formed from the original string by deleting
some (can be none) of the characters without disturbing the relative positions of the remaining characters.
(ie, "ACE" is a subsequence of "ABCDE" while "AEC" is not).

Here is an example:
S = "rabbbit", T = "rabbit"

Return 3.

*/
#include <iostream>
#include <vector>

using namespace std;

class Solution1 {
private:
    int global_slen;
    int global_tlen;

    int numDistinct_recursive(string s, string t, int s_len, int t_len, vector<int> &memo) {
        int sum = 0;

        if(t_len <= 0)
            return 1;
        if(s_len <= 0)
            return 0;

        if(memo[global_tlen * s_len + t_len] >= 0)
            return memo[global_tlen * s_len + t_len];

        sum = numDistinct_recursive(s, t, s_len-1, t_len, memo);

        if(s[s_len - 1] == t[t_len - 1])
            sum += numDistinct_recursive(s, t, s_len-1, t_len-1, memo);

        memo[global_tlen * s_len + t_len] = sum;

        return sum;
    }

public:
    int numDistinct(string s, string t){
        global_slen = s.size();
        global_tlen = t.size();
        int sum;

        vector<int> memo((global_slen+1) * (global_tlen+1), -1);
        sum = numDistinct_recursive(s, t, global_slen, global_tlen, memo);

        for(int i = 0; i< (global_slen+1) * (global_tlen+1); i++){
            cout <<  memo[i] << " ";
            if(i % 10 == 9)
                cout << endl;
        }
        return sum;
    }
};

class Solution {
public:
    int numDistinct(string s, string t) {
        int s_len = s.size();
        int t_len = t.size();
        if(s_len <= 0 || t_len <= 0)
            return 0;
/*
        vector<vector<int> > memo(t_len+1);
        for(int i = 0; i <= t_len; i++)
            for(int j = 0; j<= s_len; j++)
                memo[i].push_back(0);
*/
        int ** memo = new int *[t_len+1];
        for(int i = 0; i <= t_len; i++){
            memo[i] = new int[s_len+1];
        }
        for(int i = 0; i <= t_len; i++)
            for(int j = 0; j<= s_len; j++)
                memo[i][j] = 0;

        for(int i =0; i <= s_len; i++)
            memo[0][i] = 1;
        for(int i = 1; i <= t_len; i++)
            for(int j = 1; j<= s_len;j++)
                if(t[i-1] == s[j-1]){
                    memo[i][j] = memo[i-1][j-1] + memo[i][j-1];
                }else
                    memo[i][j] = memo[i][j-1];
/*
        for(int i = 0; i <= t_len; i++){
            for(int j = 0; j<= s_len; j++)
                cout << memo[i][j] << " ";
            cout << endl;
        }
*/
        int result = memo[t_len][s_len];
        for(int i = 0; i <= t_len; i++)
            delete [] memo[i];
        delete[] memo;

        return result;
    }
};

int main()
{
    Solution s;
    string s1 = "rabbbit";
    string t1 = "rabbit";

    cout << s.numDistinct(s1, t1) << endl;

    string s2 = "aabdbaabeeadcbbdedacbbeecbabebaeeecaeabaedadcbdbcdaabebdadbbaeabdadeaabbabbecebbebcaddaacccebeaeedababedeacdeaaaeeaecbe";
    string t2 = "bddabdcae";

    cout << s.numDistinct(s2, t2) << endl;
    return 0;
}
