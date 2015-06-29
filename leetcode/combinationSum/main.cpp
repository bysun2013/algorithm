/*
https://leetcode.com/problems/combination-sum/

Given a set of candidate numbers (C) and a target number (T),
find all unique combinations in C where the candidate numbers sums to T.

The same repeated number may be chosen from C unlimited number of times.

Note:
All numbers (including target) will be positive integers.
Elements in a combination (a1, a2, … , ak) must be in non-descending order. (ie, a1 ≤ a2 ≤ … ≤ ak).
The solution set must not contain duplicate combinations.
For example, given candidate set 2,3,6,7 and target 7,
A solution set is:
[7]
[2, 2, 3]

*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> cb;

        sort(candidates.begin(), candidates.end());
        combination(candidates, target, res, cb, 0);

        return res;
    }
private:
    void combination(vector<int>& candidates, int target, vector<vector<int>> &res, vector<int> &cb, int begin){
        if(target == 0){
            res.push_back(cb);
            return;
        }

        int len = candidates.size();
        for(int i = begin; i < len && target >= candidates[i]; i++){
            cb.push_back(candidates[i]);
            combination(candidates, target - candidates[i], res, cb, i);
            cb.pop_back();
        }
    }
};

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
