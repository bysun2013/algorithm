#include "huffman_code.h"

int huffman_coding(huffman_tree *ht,huffman_code *hc,int *w,int n)
{
    unsigned int m,i,f,s1,s2,start;
    htnode *p;
    char *cd;
    if(n<=1) return 0;
    m=2*n-1;
    *ht=(huffman_tree)malloc(sizeof(htnode)*(m));

    p=*ht;
    for(i=0; i<n; i++,w++,p++)
    {
        p->lchild=0;
        p->parent=0;
        p->rchild=0;
        p->weight=*w;
    }


    for(; i<m; i++,p++)
    {
        p->lchild=0;
        p->parent=0;
        p->rchild=0;
        p->weight=0;
    }

    for(i=n; i<m; i++)
    {
        huf_select(*ht,i-1,&s1,&s2);
        ((*ht)+i)->weight=((*ht)+s1)->weight+((*ht)+s2)->weight;
        (*ht+i)->lchild=s1;
        (*ht+i)->rchild=s2;
        (*ht+s1)->parent=i;
        (*ht+s2)->parent=i;
    }
//*************************Huffman Coding******************************
    *hc=(huffman_code)malloc(sizeof(char*)*n);
    cd=(char*)malloc(sizeof(char)*n);
    cd[n-1]='\0';
    for(i=0; i<n; i++)
    {
        int c;
        start=n-1;
        for(c=i,f=(*ht+i)->parent; f!=0; c=f,f=((*ht+f)->parent))
            if((*ht+f)->lchild==c)
                cd[--start]='1';
            else
                cd[--start]='0';
        *(*hc+i)=(char *)malloc(sizeof(char)*(n-start));
        strncpy(*(*hc+i),&cd[start],n-start);
    }
    printf("Weight\tCode\n");
    for(i=0; i<n; i++)
        printf("%d\t%s\n",(*ht+i)->weight,*(*hc+i));
    free(cd);
    return 1;
}
//this function...choose the least two number, don't know how to do it!
int huf_select(huffman_tree ht,unsigned int m,unsigned int *s1,unsigned int *s2)
{
    unsigned int i,j;
    int s[m+1][2];
    int tmp[2];
    void * ptr=tmp;
    for(i=0; i<=m; i++){
        s[i][1]=(ht+i)->weight;
        s[i][0]=i;
    }

    for(i=0;i<2;i++){
        j=i;
        while((ht+s[j][0])->parent!=0)
            j++;
        int least=j;
        for(j=i;j<=m;j++){
            if(s[least][1]>s[j][1]&&(ht+s[j][0])->parent==0)
                least=j;
        }
        memcpy(ptr,(void*)s[least],2*sizeof(int));
        memcpy((void*)s[least],(void*)s[i],2*sizeof(int));
        memcpy((void*)s[i],ptr,2*sizeof(int));
    }
    *s1=s[0][0];
    *s2=s[1][0];
    printf("%d\t%d\n",*s1,*s2);
    return 1;
}
//*************************Huffman Decoding*******************************
int huffman_traverse(huffman_tree ht,char *code)
{
    char *n=code;
    int c;
    huffman_tree hn=ht;
    while(*n){
        if(*n=='1')
            c=hn->lchild;
        else
            c=hn->rchild;
        hn=ht+c;
        n++;
    }
    printf("The weight is %d",hn->weight);
    return 1;
}
