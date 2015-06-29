/*
https://leetcode.com/problems/combination-sum-iii/

Find all possible combinations of k numbers that add up to a number n,
given that only numbers from 1 to 9 can be used and each combination should be a unique set of numbers.
Ensure that numbers within the set are sorted in ascending order.

Example 1:

Input: k = 3, n = 7
Output:
[[1,2,4]]

Example 2:

Input: k = 3, n = 9
Output:
[[1,2,6], [1,3,5], [2,3,4]]

*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> res;
        vector<int> vec;
        combination3(res, vec, k, n, 1);
        return res;
    }
private:
    void combination3(vector<vector<int>> &res, vector<int> &vec, int left, int target, int begin){
        if(left == 0){
            if(target == 0)
                res.push_back(vec);
            return;
        }

        for(int i = begin; i <= 9 && target >= i; i++){
            vec.push_back(i);
            combination3(res, vec, left -1, target - i, i+1);
            vec.pop_back();
        }
    }
};

static void show_matrix(vector<vector<int>> &res){
    int len = res.size();
    if(len <= 0)
        return;
    int col = res[0].size();
    if(col <= 0)
        return;

    for(int i = 0; i< len; i++){
        for(int j = 0; j < col; j++)
            cout << res[i][j] << " ";
        cout << endl;
    }
}

int main()
{
    Solution s;
    vector<vector<int> > res;
    int k, n;
    cin >> k >> n;
    res = s.combinationSum3(k, n);

    show_matrix(res);
    return 0;
}
