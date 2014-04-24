#include "binary_tree.h"

int create_bitree(bitree *t)
{
    char ch;
    scanf("%c",&ch);
    if(ch==' ')
        *t=NULL;
    else
    {
        *t=(bitree)malloc(sizeof(bitnode));
        if(!*t)
            return 0;
        (*t)->data=ch;
        create_bitree(&(*t)->lchild);
        create_bitree(&(*t)->rchild);
    }
    return 1;
}

int preorder_traverse_recursion(bitree t,int (*visit)(TElemType e))
{
    if(t)
    {
        if(visit(t->data))
            if(preorder_traverse_recursion(t->lchild,visit))
                if(preorder_traverse_recursion(t->rchild,visit))
                    return 1;
        return 0;
    }
    else
        return 1;
}
int inorder_traverse_recursion(bitree t,int (*visit)(TElemType e))
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
int postorder_traverse_recursion(bitree t,int (*visit)(TElemType e))
{
    if(t)
    {

        if(postorder_traverse_recursion(t->lchild,visit))
            if(postorder_traverse_recursion(t->rchild,visit))
                if(visit(t->data))
                    return 1;
        return 0;
    }
    else
        return 1;
}


int preorder_traverse(bitree t,int (*visit)(TElemType e))
{
    stack s;
    bitnode *bn;
    initStack(&s);
    push(&s,t);
    while(!isEmpty_S(s))
    {
        while(pop(&s,&bn)&&bn){
            visit(bn->data);
            if(bn->rchild) push(&s,bn->rchild);
            push(&s,bn->lchild);
        }

    }
    destroyStack(&s);
    return 1;
}
int inorder_traverse(bitree t,int (*visit)(TElemType e)){
    stack s;
    bitnode *bn;
    initStack(&s);
    push(&s,t);
    while(!isEmpty_S(s))
    {
        while(getTop(s,&bn)&&bn) push(&s,bn->lchild);
        pop(&s,&bn);
        if(!isEmpty_S(s))
        {
            pop(&s,&bn);
            visit(bn->data);
            push(&s,bn->rchild);
        }
    }
    destroyStack(&s);
    return 1;
}

int inorder_traverse_other(bitree t,int (*visit)(TElemType e)){
    stack s;
    bitree p=t;
    initStack(&s);
    while(p||!isEmpty_S(s)){
        if(p){
            push(&s,p);
            p=p->lchild;
        }else{
            pop(&s,&p);
            visit(p->data);
            p=p->rchild;
        }

    }
     destroyStack(&s);
     return 1;
}

int postorder_traverse(bitree t,int (*visit)(TElemType e)){
    stack s;
    bitnode *bn;
    int tag[STACK_INIT_SIZE];
    initStack(&s);
    bn=t;
    while(bn||!isEmpty_S(s))
    {
        while(bn){
            push(&s,bn);
            tag[s.top-s.base]=1;
            bn=bn->lchild;
        }
       while(!isEmpty_S(s)&&tag[s.top-s.base]==2){
            pop(&s,&bn);
            visit(bn->data);
        }
        if(!isEmpty_S(s)){
            tag[s.top-s.base]=2;
            getTop(s,&bn);
            bn=bn->rchild;
        }else
            break;
    }
    destroyStack(&s);

    return 1;
}
int levelorder_traverse(bitree t,int (*visit)(TElemType e)){
    RoundQueue rq;
    bitnode *p;
    initQueue(&rq);
    enQueue(&rq,t);

    while(!isEmpty_Q(&rq)){
        while(getHead(&rq,&p)&&p){
            deQueue(&rq,&p);
            visit(p->data);
            if(p->lchild) enQueue(&rq,p->lchild);
            if(p->rchild) enQueue(&rq,p->rchild);
        }
    }
    destoyQueue(&rq);
    return 1;
}

int visit(TElemType e)
{
    printf("%c",e);
    return 1;
}
