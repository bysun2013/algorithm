/*
https://leetcode.com/problems/edit-distance/

Given two words word1 and word2, find the minimum number of steps required to
convert word1 to word2. (each operation is counted as 1 step.)

You have the following 3 operations permitted on a word:

a) Insert a character
b) Delete a character
c) Replace a character
*/

#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    int minDistance(string word1, string word2) {
        int len1 = word1.size();
        int len2 = word2.size();
        if(len1 == 0)
            return len2;
        else if(len2 == 0)
            return len1;

        int **a = new int*[len1+1];
        for(int i = 0; i<= len1; i++)
            a[i] = new int[len2+1];

        for(int i = 0; i<= len1; i++)
            a[i][0] = i;
        for(int i = 1; i<= len2; i++)
            a[0][i] = i;
        for(int i = 1; i<= len1; i++){
            for(int j = 1; j<= len2; j++){
                if(word1[i-1] == word2[j-1])
                    a[i][j] = a[i-1][j-1];
                else{
                    int min_distance = a[i-1][j-1];
                    if(min_distance > a[i][j-1])
                        min_distance = a[i][j-1];
                    if(min_distance > a[i-1][j])
                        min_distance = a[i-1][j];
                    a[i][j] = min_distance+1;
                }
            }
        }
        int result = a[len1][len2];

        for(int i = 0; i<= len1; i++)
            delete [] (a[i]);

        delete [] a;
        return result;
    }
};

int main()
{
    Solution s;
    string word1 = "a";
    string word2 = "d";

    cout << s.minDistance(word1, word2) << endl;
    return 0;
}
