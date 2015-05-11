/*
https://leetcode.com/problems/n-queens/

Given an integer n, return all distinct solutions to the n-queens puzzle.

Each solution contains a distinct board configuration of the n-queens' placement,
where 'Q' and '.' both indicate a queen and an empty space respectively.

For example,
There exist two distinct solutions to the 4-queens puzzle:

[
 [".Q..",  // Solution 1
  "...Q",
  "Q...",
  "..Q."],

 ["..Q.",  // Solution 2
  "Q...",
  "...Q",
  ".Q.."]
]

*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<string> > solveNQueens(int n) {
        vector<vector<string> > result;
        if(n <= 0 || (n > 1 && n < 4))
            return result;

        int *solves = new int[n];
        dfs(solves, n, 0, result);

        delete [] solves;
        return result;
    }
private:
    void dfs(int *solves, int n, int depth, vector<vector<string> > &result){
        if(depth >= n){
            //print to result;
            vector<string> v;

            for(int i = 0; i< n ; i++){
                string s;
                for(int j = 0; j< n; j++){
                    if(solves[i] == j)
                        s.push_back('Q');
                    else
                        s.push_back('.');
                }
                v.push_back(s);
            }
            result.push_back(v);
            return;
        }

        for(int i = 0;i < n; i++){
            if(is_valid_choice(solves, depth, i)){
                    solves[depth] = i;
                    dfs(solves, n, depth + 1, result);
            }
        }
    }
    bool is_valid_choice(int *solves, int depth, int choice){
        for(int i = 0; i< depth; i++){
            if(solves[i] == choice)
                return false;
            if(solves[i] - choice == i - depth || solves[i] - choice == depth - i)
                return false;
        }
        return true;
    }
};

int main()
{
    Solution s;
    int n;
    cin >> n;
    vector<vector<string> > result = s.solveNQueens(n);

    int total = result.size();
    if(total <= 0)
        return 0;
    int row = result[0].size();
    for(int i = 0; i < total;i++){
        for(int j = 0; j < row; j++)
            cout << result[i][j] << endl;
        cout << endl;
    }

    return 0;
}
