#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

using namespace std;

const int brancheslen = 20;
int branches[brancheslen][100] = {
{10030,900},{9999, 9998},{10001,990},{88007,887},{9870,978},
{1001,901},{992,883},{992,883},{1005,993},{987,979},
{1002,902},{993,884},{1008,993},{887,877},{987,980},
{1002,902},{993,884},{1008,993},{887,877},{9807,980}
};

/*非叶子结点*/
int tree[brancheslen];
/*叶子结点*/
int nodes[brancheslen];

int nodes_iterator[brancheslen] = {0};
static void put(int index)
{
    nodes[index] = branches[index][nodes_iterator[index]++];
}

static int get(int index)
{
    return nodes[index];
}

static void adjust(int index)
{
    int parent = (index+1+brancheslen-1)/2;

    while(parent > 0){
        if(get(tree[parent]) > get(index)){
            int tmp = tree[parent];
            tree[parent] = index;
            index = tmp;
        }
        parent /= 2;
    }
    tree[0] = index;
}

static void tree_init()
{
    int winner = 0;
    for(int i=0; i<brancheslen; i++)
        put(i);
    for(int i = 1; i < brancheslen; i++){
        if(get(i) > get(winner)){
            winner = i;
        }
    }
    for(int i = 1; i< brancheslen;i++)
        tree[i] = winner;

    for(int i = brancheslen - 1; i >= 0; i--)
        adjust(i);
}

vector<int> largest(int k)
{
    vector<int> result;
    int i = 0;
    while(i < k){
        result.push_back(get(tree[0]));
        i++;
        put(tree[0]);
        adjust(tree[0]);
    }

    return result;
}

int main()
{
    int k;
    cin >> k;

    tree_init();
    vector<int> result = largest(k);

    copy(result.begin(), result.end(), ostream_iterator<int>(cout, " "));
    return 0;
}
