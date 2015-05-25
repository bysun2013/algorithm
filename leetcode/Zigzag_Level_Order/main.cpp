/*
https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/

Given a binary tree, return the zigzag level order traversal of its nodes' values.
(ie, from left to right, then right to left for the next level and alternate between).

For example:
Given binary tree {3,9,20,#,#,15,7},
    3
   / \
  9  20
    /  \
   15   7
return its zigzag level order traversal as:
[
  [3],
  [20,9],
  [15,7]
]

so sad, it cost me one hour...
*/

#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> result;
        if(!root)
            return result;
        queue<TreeNode *> q1; // store single
        queue<TreeNode *> q2; //store double
        int len = 1;

        q1.push(root);
        while(1){
            TreeNode *node;
            if(len & 1){
                if(q1.empty())
                    break;
                vector<int> tmp;
                while(!q1.empty()){
                    node = q1.front();
                    q1.pop();
                    tmp.push_back(node->val);

                    if(node->left)
                        q2.push(node->left);
                    if(node->right)
                        q2.push(node->right);
                }
                //reverse(tmp.begin(), tmp.end());
                result.push_back(tmp);
            }else{
                if(q2.empty())
                    break;
                vector<int> tmp;
                while(!q2.empty()){
                    node = q2.front();
                    q2.pop();
                    tmp.push_back(node->val);

                    if(node->left)
                        q1.push(node->left);
                    if(node->right)
                        q1.push(node->right);
                }
                reverse(tmp.begin(), tmp.end());
                result.push_back(tmp);
            }
            len++;
        }
        return result;
    }
};

int main()
{
    Solution s;
    s.zigzagLevelOrder(NULL);
    return 0;
}
