#include "intset.h"
#include <iostream>
using namespace std;

IntSet::IntSet(void)
{
    root = NULL;
}

void IntSet::free_nodes(struct node *root)
{
    if(t->left)
        free_nodes(t->left);
    if(t->right)
        free_nodes(t->left);

    free(root);
}

IntSet::~IntSet(void)
{
//    free_nodes(root);
}

void IntSet::insert(int x)
{
    struct node *node = malloc(sizeof(struct node));
    struct node *t = root, *p = NULL;
    node->value = x;

    while(t != NULL){
        if(t->value == x){
            free(node);
            return;
        }else if(t->value > x){
            p = t;
            t = t->left;
        }else{
            p = t;
            t = t->right;
        }
    }

    if(p->value > x)
        p->left = node;
    else
        p->right = node;
}

void IntSet::traverse(void)
{
    struct node *t = root;

    while(t != NULL){
        if
    }

}

bool IntSet::IsEqual(const IntSet & s)
{
	return false;
}

//求两个set的交
IntSet & IntSet::union2(const IntSet & s1, const IntSet & s2)
{
	return *this;
}

//求两个set的并
IntSet & IntSet::incorporate2(const IntSet & s1, const IntSet & s2)
{
	return *this;
}

void IntSet::print(void)
{
	cout<<"just for fun!\n"<<endl;
}
