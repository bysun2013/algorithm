#include "BiThrTree.h"

int creat_threadtree(bithr_tree *t)
{
    char ch;
    scanf("%c",&ch);
    if(ch==' ')
        *t=NULL;
    else
    {
        *t=(bithr_tree)malloc(sizeof(bithr_node));
        if(!*t)
            return 0;
        (*t)->data=ch;
        (*t)->ltag=LINK;
        (*t)->rtag=LINK;
        creat_threadtree(&(*t)->lchild);
        creat_threadtree(&(*t)->rchild);
    }
    return 1;
}

int destroy_threadtree(bithr_tree t){
    if(t){
        if((t)->ltag==LINK) destroy_threadtree(((t)->lchild));
        if((t)->rtag==LINK) destroy_threadtree(((t)->rchild));
        free(t);
    }
    printf("This is freed!\n");
   return 1;
}
static bithr_node *pre;

int inorder_threading(bithr_tree *thrt,bithr_tree t)
{

    if(!(*thrt=(bithr_node*)malloc(sizeof(bithr_node))))
        return 0;
    (*thrt)->ltag=LINK; (*thrt)->rtag=THREAD;
    (*thrt)->rchild=*thrt;
    if(!t)
        (*thrt)->lchild=(*thrt);
    else{
        (*thrt)->lchild=t;
        pre=*thrt;
        inthreading(t);
        pre->rchild=*thrt;
        pre->rtag=THREAD;
        (*thrt)->rchild=pre;
    }

    return 1;
}

//this recursion is very very difficult to understand it! Believe it or not, I believe!
void inthreading(bithr_tree p)
{
    if(p){
        inthreading(p->lchild);
        if(!p->lchild) {
            p->ltag=THREAD;
            p->lchild=pre;
        }
        if(!pre->rchild){
            pre->rtag=THREAD;
            pre->rchild=p;
        }
        pre=p;
        inthreading(p->rchild);
    }
}

int inorder_traverse_recursion(bithr_tree t,int (*visit)(thr_elem_type e))
{
    if(t)
    {
        if(inorder_traverse_recursion(t->lchild,visit))
            if(visit(t->data))
                if(inorder_traverse_recursion(t->rchild,visit))
                    return 1;
        return 0;
    }
    else
        return 1;
}

int inorder_traverse_thr(bithr_tree t,int (*visit)(thr_elem_type e)){
    bithr_node *bt=t->lchild;
    while(bt!=t){
        while(bt->ltag==LINK) bt=bt->lchild;
        if(!visit(bt->data)) return 0;
        while(bt->rtag==THREAD&&bt->rchild!=t) {
                bt=bt->rchild;
                visit(bt->data);
        }
        bt=bt->rchild;
    }
    return 1;
}

int visit(thr_elem_type e)
{
    printf("%c\t",e);
    return 1;
}
