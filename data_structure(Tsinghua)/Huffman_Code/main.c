#include <stdio.h>
#include <stdlib.h>
#include "huffman_code.h"
int main()
{
    int weight[4]={7,5,2,4};
    huffman_tree ht;
    huffman_code hc;
    huffman_coding(&ht,&hc,weight,4);

    printf("Hello world!\n");
    return 0;
}
