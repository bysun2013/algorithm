/*
https://leetcode.com/problems/sum-root-to-leaf-numbers/

Given a binary tree containing digits from 0-9 only, each root-to-leaf path could represent a number.

An example is the root-to-leaf path 1->2->3 which represents the number 123.

Find the total sum of all root-to-leaf numbers.

For example,

    1
   / \
  2   3
The root-to-leaf path 1->2 represents the number 12.
The root-to-leaf path 1->3 represents the number 13.

Return the sum = 12 + 13 = 25.
*/

#include <iostream>
using namespace std;

/**
 * Definition for a binary tree node.
 */
 struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

class Solution {
public:
    int sumNumbers(TreeNode* root) {
        if(!root)
            return 0;
        sum = 0;

        dfs_cost(root, 0);

        return sum;
    }
private:
    int sum;
    void dfs_cost(TreeNode* root, int value){
        if(!root)
            return;
        int cur_value = value*10 + root->val;
        if(!root->left && !root->right){
            sum += cur_value;
            return;
        }
        dfs_cost(root->left, cur_value);
        dfs_cost(root->right, cur_value);
    }
};

int main()
{
    Solution s;
    cout << s.sumNumbers(NULL) << endl;

    return 0;
}
