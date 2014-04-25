/**
    题目：输入数字n，按顺序输出从1最大的n位10进制数。
    比如输入3，则输出1、2、3一直到最大的3位数即999。

    分析：这是一道很有意思的题目。看起来很简单，其实里面却有不少的玄机。
    如果我们仔细分析这个问题，就能注意到这里没有规定n的范围，
    当我们求最大的n位数的时候，是不是有可能用整型甚至长整型都会溢出？

    Done in 2014.4.25 by B.Y.Sun
*/
#include <stdio.h>
#include <stdlib.h>
static char *num;
void build_sub(char *s){
    int i;
    if(*s=='\0'){
        char *tmp=num;
        while(*tmp=='0')
            tmp++;
        printf("%s ", tmp);
        return;
    }
    for(i=0;i<10;i++){
        s[0]='0'+i;
        build_sub(s+1);
    }
}

void print_n(int digit){
    num=malloc(sizeof(char)*(digit+1));
    int i=0;
    for(;i<digit;i++){
        num[i]='0';
    }
    num[digit]='\0';
    printf("The number from 0 to N-digit:\n");
    build_sub(num);
}

int main()
{
    int digit;
    printf("Please enter a number: ");
    scanf("%d", &digit);
    print_n(digit);
    return 0;
}
