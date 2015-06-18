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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> result;

        stack<TreeNode *> s;
        TreeNode *node = root;

        while(!s.empty() || node){
                if(node){
                    s.push(node);
                    s.push(node->right);
                    node = node->left;
                }else{
                    node = s.top();
                    s.pop();
                    if(!node){
                        node = s.top();
                        s.pop();
                        result.push_back(node->val);
                        if(s.empty())
                            break;
                        node = s.top();
                        s.pop();
                    }
                    s.push(NULL);
                }
        }
        return result;
    }
};

int main()
{
    Solution s;
    s.postorderTraversal(NULL);
    cout << "Hello world!" << endl;
    return 0;
}
