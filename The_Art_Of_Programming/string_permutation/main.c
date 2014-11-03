/*
* 输入一个字符串，打印出该字符串中字符的所有排列。
* 例如输入字符串abc，则输出由字符a、b、c 所能排列出来的所有字符串
* abc、acb、bac、bca、cab 和 cba。
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *str;
int total;
static void swap(char *s, int a, int b)
{
    char tmp;
    if(a == b)
        return;

    tmp = s[a];
    s[a] = s[b];
    s[b] = tmp;
}
/* 使用递归算法，从右向左循环交换 */
static int permutation(char *s, int length){
    int i;

    if(length <= 1){
        printf("The string is %s\n", str);
        return 0;
    }

    for(i=0;i<length;i++){
        swap(s, 0, i);
        permutation(&s[1], length - 1);
        swap(s, i, 0);
    }
    return 0;
}

int quick_sort(char* s, int start, int end)
{
    int i = start;
    int j = end;
    char tmp = s[j];

    if(end <= start)
        return 0;

    while(i < j){
        while(i < j && s[i] <= tmp)
            i++;
        if(i < j){
            s[j] = s[i];
            j--;
        }


        while(i < j && s[j] > tmp)
            j--;
        if(i < j){
            s[i] = s[j];
            i++;
        }
    }

    s[i] = tmp;
    quick_sort(s, start, i-1);
    quick_sort(s, i+1, end);

    return 0;
}

/* s must be in order */
int alphabet_order(char* str, int len)
{
    int i = 0,j = 0;
    char *s = str;

    while(i < len && s[i] < s[i+1])
        i++;

    j = i;
    while(j < len && s[j] > s[j+1])
        j++;
    if(i < j){
        swap(s, i, j);
        quick_sort(s, i+1, j);
    }
}

#define MAX_LEN 100
int main()
{
    char s[MAX_LEN];
    int len;

    str = s;
    printf("Please enter a string:\n");
    scanf("%s", s);

    len = strlen(s);
    //permutation(s, len);

    quick_sort(s, 0, len-1);
    printf("%s\n", s);
    return 0;
}
