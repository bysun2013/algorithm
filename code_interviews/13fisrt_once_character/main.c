/**
题目：在一个字符串中找到第一个只出现一次的字符。如输入abaccdeff，则输出b。

    分析：这道题是2006年google的一道笔试题。

    Done in 2014.4.7
*/

#include <stdio.h>
#include <stdlib.h>


/** 可以用一个辅助数组记录只有一次字符出现的索引值
    在最后通过找到这个辅助数组的最小有效值来的到最终结果字符
    该方法比较复杂，但是它的时间复杂度为O(n)
*/
#define ASCII_NUM 127
#define MAX_NUM 100
int first_once_character(char *s){
    int count[ASCII_NUM];
    int index[ASCII_NUM];
    char *p=s;
    int i=0;

    memset(count, 0 ,ASCII_NUM*sizeof(int));
    memset(index, -1 ,ASCII_NUM*sizeof(int));

    while(*p!='\0'){
        count[*p]++;

        if(count[*p]==1){
            index[*p]=i;
        }else if(count[*p]>1)
            index[*p]=-1;
        p++;
        i++;
    }

    int min=i, j=0;
    while(j<ASCII_NUM){
        if(index[j]>=0 && min>index[j]){
                min=index[j];
        }
        j++;
    }

    char first_ch=0;
    if(min<i){
        first_ch=*(s+min);
        printf("The first once character is: %c\n", first_ch);
    }else
        printf("There is no the first once character\n");

    return 0;
}

int main()
{
    char s[MAX_NUM];
    printf("Please enter a string:\n");
    scanf("%s", s);

    first_once_character(s);
    return 0;
}
