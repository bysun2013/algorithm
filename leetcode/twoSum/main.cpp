/*
https://leetcode.com/problems/two-sum/

Given an array of integers, find two numbers such that they add up to a specific target number.

The function twoSum should return indices of the two numbers such that they add up to the target,
where index1 must be less than index2. Please note that your returned answers
(both index1 and index2) are not zero-based.

You may assume that each input would have exactly one solution.

Input: numbers={2, 7, 11, 15}, target=9
Output: index1=1, index2=2

*/
#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <iterator>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int len  = nums.size();
        vector<int> result;
        unordered_map<int, int> nhash;
        for(int i = 0; i< len; i++){
            if(nhash.find(nums[i]) == nhash.end()){
                    nhash[nums[i]] = i;
            }
            if(nhash.find(target - nums[i]) != nhash.end()){
                int index = nhash[target - nums[i]];
                if(index < i){
                    result.push_back(index+1);
                    result.push_back(i+1);
                }
            }
        }
        return result;
    }
};

int main()
{
    int a[] = {18,9,7,5,3};
    vector<int> v(a,a+5);
    Solution s;
    vector<int> result = s.twoSum(v, 14);
    copy(result.begin(), result.end(), ostream_iterator<int>(cout, " "));
    return 0;
}
