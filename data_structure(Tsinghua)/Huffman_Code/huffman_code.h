#ifndef HUFFMAN_CODE_H_INCLUDED
#define HUFFMAN_CODE_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    unsigned int weight;
    unsigned int parent,lchild,rchild;
}htnode,*huffman_tree;

typedef char ** huffman_code;

int huffman_coding(huffman_tree *ht,huffman_code *hc,int *w,int n);
int huf_select(huffman_tree ht,unsigned int m,unsigned int *s1,unsigned int *s2);
int huffman_traverse(huffman_tree ht,char *code);

#endif // HUFFMAN_CODE_H_INCLUDED
