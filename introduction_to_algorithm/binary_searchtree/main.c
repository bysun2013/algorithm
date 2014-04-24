#include <stdio.h>
#include <stdlib.h>

typedef int TElemType;

typedef struct bnode{
    TElemType key;
    struct bnode *lchild,*rchild;
    struct bnode *parent;
}bnode;

/**
    @x 二叉树的根节点
    此处两个函数实现相同的功能，1.递归 2.遍历
*/
struct bnode* search_tree(struct bnode* x, int k){
    if(x==NULL || x->key==k)
        return x;
    if(k<x->key)
        return search_tree(x->lchild, k);
    else
        return search_tree(x->rchild, k);
}

struct bnode* iterative_search_tree(struct bnode* x, int k){
    while(x!=NULL && x->key!=k){
            if(k<x->key)
                x=x->lchild;
            else
                x=x->rchild;
    }
    return x;
}

struct bnode* maximum_tree(struct bnode *root){
    if(root==NULL)
        return NULL;
    while(root->rchild!=NULL)
        root=root->rchild;
    return root;
}

struct bnode* minimum_tree(struct bnode *root){
    if(root==NULL)
        return NULL;
    while(root->lchild!=NULL)
        root=root->lchild;
    return root;
}
/**
    @root 它的parent必须是NULL
*/
void insert_node(struct bnode **root, struct bnode *z){
    struct bnode *p=NULL, *x=*root;
    while(x!=NULL){
            p=x;
            if(x->key>z->key)
                x=x->lchild;
            else
                x=x->rchild;
    }
    z->parent=p;
    if(p==NULL)
        *root=z;
    else if(z->key>p->key)
        p->rchild=z;
    else
        p->lchild=z;
}
/**
    @root 它的parent必须是NULL
    @u 被v替代的结点
    @v 替代u的结点
    此处只是简单的替换，并没有更新二叉树；
    调用者负责更新二叉树
*/
static void transplant(struct bnode **root, struct bnode *u, struct bnode *v){
    if(u->parent==NULL)
        *root=v;
    else if(u->parent->lchild==u)
        u->parent->lchild=v;
    else if(u->parent->rchild==u)
        u->parent->rchild=v;

    if(v!=NULL)
        v->parent=u->parent;
}
int delete_node(struct bnode **root, struct bnode *z){
    struct bnode* t;
    if(z->lchild==NULL){
        transplant(root, z, z->rchild);
    }else if(z->rchild==NULL){
        transplant(root, z, z->lchild);
    }else{
        t=minimum_tree(z->rchild);
        if(t!=z->rchild){
            transplant(root, t, t->rchild);
            t->rchild=z->rchild;
            t->rchild->parent=t;
        }
        transplant(root, z, t);
        t->lchild=z->lchild;
        t->lchild->parent=t;
    }
    return 0;
}

int inorder_traverse_recursion(struct bnode* t,int (*visit)(TElemType e))
{
    if(t)
    {
        if(inorder_traverse_recursion(t->lchild,visit))
            if(visit(t->key))
                if(inorder_traverse_recursion(t->rchild,visit))
                    return 1;
        return 0;
    }
    return 1;
}

int visit(TElemType e)
{
    printf("%d\t",e);
    return 1;
}


int create_tree(struct bnode **root){
    struct bnode *node;
    int size,key;
    int i=0;
    printf("The length of binary search tree:");
    scanf("%d",&size);

    printf("Please enter the keys of binary search tree:\n");
    while(i<size){
        scanf("%d",&key);
        node=(struct bnode*)malloc((sizeof(struct bnode)));
        node->key=key;
        node->parent=NULL;
        node->lchild=NULL;
        node->rchild=NULL;
        insert_node(root,node);
        i++;
    }
    return 0;
}

int main()
{
    struct bnode *root=NULL;
    create_tree(&root);
    printf("after sort binary search tree: \n");
    inorder_traverse_recursion(root,visit);

    delete_node(&root,root);

    printf("\nafter delete root, binary search tree: \n");
    inorder_traverse_recursion(root,visit);
    return 0;
}
