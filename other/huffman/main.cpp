#include <iostream>
#include <queue>
#include <map>
#include <string>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

struct binary_node{
    struct binary_node *left, *right;
    char value;
    binary_node(char c = '#'):left(NULL),right(NULL),value(c){}
};

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


typedef pair<binary_node*, int> pq_type;
typedef pair<char, int> vec_type;

class node_less{
public:
    bool operator()(const pq_type &a, const pq_type &b)
    {
        /* 构造最小堆 */
        if(a.second > b.second)
            return true;
        return false;
    }
};

binary_node* build_huffman(vector<vec_type> &v)
{
    priority_queue<pq_type, vector<pq_type>, node_less> pq;
    for(vector<vec_type>::const_iterator it = v.begin(); it != v.end(); it++){
        binary_node *node = new binary_node(it->first);
        pq.push(pq_type(node, it->second));
    }

    while(pq.size() > 1){
        pq_type t1, t2;
        t1 = pq.top();
        pq.pop();
        t2 = pq.top();
        pq.pop();

        binary_node *root = new binary_node();
        root->left = t1.first;
        root->right = t2.first;
        pq.push(pq_type(root, t1.second + t2.second));
    }
    pq_type r = pq.top();
    pq.pop();
    return r.first;
}

vec_type map_to_vec(vec_type t){
    return t;
}

int main()
{
    map<char, int> m;
    vector<vec_type> v;
    string s;
    cin >> s;

    for(size_t i = 0; i< s.size(); i++)
        m[s[i]]++;

    transform(m.begin(), m.end(), back_inserter(v), map_to_vec);
    binary_node* root = build_huffman(v);
    cout << "Hello world!" << endl;

    traverse_pre(root);
    traverse_in(root);
    traverse_post(root);
    return 0;
}
