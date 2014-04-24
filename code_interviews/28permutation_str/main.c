/**
题目：
    输入一个字符串，打印出该字符串中字符的所有排列。
    例如输入字符串abc，则输出由字符a、b、c所能排列出来的所有字符串：
        abc、acb、bac、bca、cab和cba

    Done in 2014.4.20 by B.Y.Sun

    PS:该题比较难以理解，仔细考虑交换的过程！
*/
#include <stdio.h>
#include <stdlib.h>

static void swap(char *s, char *t){
    char tmp;
    if(s==t)
        return;
    tmp=*s;
    *s=*t;
    *t=tmp;
}
void permutation(char *s, char *pos){

    if(!s || !pos)
        return;

    if(*pos == '\0'){
        printf("%s\n", s);
    }else{
        char *tmp=pos;
        for(;*tmp!='\0';tmp++){
            swap(pos, tmp);
            permutation(s, pos+1);
            swap(pos, tmp);
        }
    }
}

int main()
{
    char s[]="abcd";
    permutation(s,s);
    return 0;
}
