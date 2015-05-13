/*
题目25：
输入一个二叉树和一个整数，打印出二叉树中节点值的和为输入整数的所有路径。
从根节点开始一直到叶节点所经过的结点形成一个路径。

该算法没有经过测试！
*/
#include <iostream>
#include <vector>

using namespace std;

struct binary_node
{
    int value;
    struct binary_node *left, *right;
};

void print_path(vector<int> path)
{
    int len = path.size();

    for(int i = 0; i< len; i++)
        cout << path[i] << " ";

    cout << endl;
}

void find_path(struct binary_node *root, int expected, int current_sum, vector<int> &path)
{
    current_sum += root->value;
    path.push_back(root->value);

    if(!root->left && !root->right)
    {
        if(current_sum == expected)
            print_path(path);
        path.pop_back();
        return;
    }

    if(root->left)
        find_path(root->left, expected, current_sum, path);
    if(root->right)
        find_path(root->right, expected, current_sum, path);

    path.pop_back();
    return;
}

void find_path(struct binary_node *root, int expected)
{
    if(!root)
        return;

    vector<int> path;
    find_path(root, expected, 0, path);
}

int main()
{
    vector<int> path;
    int n;
    struct binary_node *root = NULL;
    cin>> n;

    find_path(root, n);
    return 0;
}
