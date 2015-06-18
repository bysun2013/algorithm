#include <iostream>
#include <vector>
#include <stack>

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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> result;

        TreeNode *node = root;
        stack<TreeNode* > s;

        while(!s.empty() || node){
                if(node){
                    result.push_back(node->val);
                    s.push(node->right);
                    node = node->left;
                }else{
                    node = s.top();
                    s.pop();
                }
        }
        return result;
    }
};

int main()
{
    Solution s;
    s.preorderTraversal(NULL);
    return 0;
}
