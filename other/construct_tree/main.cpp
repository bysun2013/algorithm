/**
利用给出的前序遍历和中序遍历，判断是否可以构建二叉树
*/

#include <iostream>
#include <vector>
#include <stdexcept>
#include <algorithm>
#include <stack>

using namespace std;

struct binary_node{
    int value;
    struct binary_node *left, *right;
    binary_node(int t):value(t), left(NULL), right(NULL){}
};

struct binary_node* construct_core(vector<int>::const_iterator start_preorder, vector<int>::const_iterator end_preorder,
                                   vector<int>::const_iterator start_inorder, vector<int>::const_iterator end_inorder)
{
   if(start_preorder == end_preorder){
        if(start_inorder != end_inorder)
            throw invalid_argument("invalid input");
        return NULL;
   }
   int middle = *start_preorder;

   struct binary_node* root = new binary_node(middle);
   vector<int>::const_iterator rootinorder = find(start_inorder, end_inorder, middle);
   if(rootinorder == end_inorder){
        throw invalid_argument("Invalid input");
   }
    int left_length = rootinorder - start_inorder;
   root->left = construct_core(start_preorder + 1, start_preorder + 1 + left_length, start_inorder, rootinorder);
   root->right = construct_core(start_preorder + 1 + left_length, end_preorder, rootinorder + 1, end_inorder);

   return root;
}

struct binary_node* construct(const vector<int> &preorder, const vector<int> &inorder)
{
    struct binary_node *root;
    root = construct_core(preorder.begin(), preorder.end(), inorder.begin(), inorder.end());

    return root;
}
void traverse_pre(struct binary_node *root)
{
    cout << "preorder traverse: " <<endl;
    if(!root)
        return;
    struct binary_node *rt = root;

    stack<struct binary_node *> s;

    while(rt || !s.empty()){
        if(rt){
            cout << rt->value << " ";
            s.push(rt->right);
            rt = rt->left;
        }else{
            rt = s.top();
            s.pop();
        }
    }
    cout << endl;
}

void traverse_in(struct binary_node *root)
{
    cout << "inorder traverse: " <<endl;
    if(!root)
        return;
    struct binary_node *rt = root;
    stack<struct binary_node *> s;

    while(rt || !s.empty()){
        if(rt){
            s.push(rt);
            rt = rt->left;
        }else{
            rt = s.top();
            s.pop();
            cout << rt->value << " ";
            rt = rt->right;
        }
    }
    cout << endl;
}

void traverse_post(struct binary_node *root)
{
    if(!root)
        return;
    struct binary_node * rt = root;
    stack<struct binary_node *> s;

    cout << "Traverse postorder: " << endl;
    while(1){
        if(rt){
            s.push(rt);
            s.push(rt->right);
            rt = rt->left;
        }else{
            rt = s.top();
            s.pop();
            if(!rt){
                rt = s.top();
                s.pop();
                cout << rt->value << " ";
                if(s.empty()){
                    cout << endl;
                    return;
                }
                rt = s.top();
                s.pop();
            }
            s.push(NULL);
        }
    }

}

bool isBST(struct binary_node *root, int *max_root)
{
    if(!root)
        return true;
    if(!max_root)
        throw invalid_argument("max_root can't be NULL");

    int r = root->value;
    int left = 0, right = 0;
    *max_root = r;
    if(root->left){
        if(!isBST(root->left, &left))
            return false;
        if(left > r)
            return false;
    }

    if(root->right){
        if(!isBST(root->right, &right))
            return false;
        if(right < r)
            return false;
        *max_root = right;
    }

    return true;
}

int main()
{
    /*
    int pre[] = {1,2,4,7,3,5,6,8};
    int in[] = {4,7,2,1,5,3,8,6};
*/
    int pre[] = {6,2,1,4,3,8};
    int in[] = {1,2,3,4,6,8};
    vector<int> preorder(pre, pre + 6);
    vector<int> inorder(in, in + 6);
    struct binary_node * root;
/*
    cout << "NULL:" << endl;
    root = construct(vector<int>(), vector<int>());
    traverse_post(root);
    cout << endl;

    cout << "both left and right:" << endl;
*/
    root = construct(preorder, inorder);

    traverse_pre(root);
    traverse_in(root);
    traverse_post(root);
    int tmp;
    cout << "the tree is BST ?" << boolalpha << isBST(root, &tmp) << endl;

    return 0;
}
