/*

https://leetcode.com/problems/combination-sum-ii/

Given a collection of candidate numbers (C) and a target number (T),
find all unique combinations in C where the candidate numbers sums to T.

Each number in C may only be used **once** in the combination.

Note:
All numbers (including target) will be positive integers.
Elements in a combination (a1, a2, … , ak) must be in non-descending order. (ie, a1 ≤ a2 ≤ … ≤ ak).
The solution set must not contain duplicate combinations.
For example, given candidate set 10,1,2,7,6,1,5 and target 8,
A solution set is:
[1, 7]
[1, 2, 5]
[2, 6]
[1, 1, 6]

*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> cb;

        sort(candidates.begin(), candidates.end());
        combination2(candidates, target, res, cb, 0);

        return res;
    }
private:
    void combination2(vector<int>& candidates, int target, vector<vector<int>> &res, vector<int> &cb, int begin){
        if(target == 0){
            res.push_back(cb);
            return;
        }

        int len = candidates.size();
        for(int i = begin; i < len && target >= candidates[i]; i++){
            if(i == begin || candidates[i] != candidates[i-1]){   // 好好思考理解！！
                cb.push_back(candidates[i]);
                combination2(candidates, target - candidates[i], res, cb, i+1);
                cb.pop_back();
            }

        }
    }
};
int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
