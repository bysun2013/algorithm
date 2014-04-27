/**
    题目：输入一个正整数数组，将它们连接起来排成一个数，输出能排出的所有数字中最小的一个。
    例如输入数组{32, 321}，则输出这两个能排成的最小数字32132

    PS: 重写compare函数；借鉴C++的思想:操作符的重载

    Done in 2014.4.27 by B.Y.Sun
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 10

static int compare(const char *s1, const char *s2){
    int result;
    char *n1=malloc(sizeof(char)*(2*MAX_LEN+1));
    char *n2=malloc(sizeof(char)*(2*MAX_LEN+1));

    strcpy(n1, s1);
    strcat(n1,s2);

    strcpy(n2, s2);
    strcat(n2,s1);

    result=strcmp(n1,n2);
    free(n1);
    free(n2);
    return result;
}

static void sort_string(char *arr[], int n){
    int i,j;
    for(i=0;i<n;i++){
        for(j=i;j<n;j++){
            if(compare(arr[i],arr[j])>0){
                char *p;
                p=arr[i];
                arr[i]=arr[j];
                arr[j]=p;
            }
        }
    }
}

int min_concat(int arr[], int n){
    int i;
    char **p;
    p=(char **)malloc(sizeof(char *)*n);
    for(i=0;i<n;i++){
        p[i]=(char *)malloc(sizeof(char)*(1+MAX_LEN));
        memset(p[i], sizeof(char)*(1+MAX_LEN), 0);
        itoa(arr[i], p[i], 10);
    }
    sort_string(p, n);
    printf("The minimal concat number is:\n");
    for(i=0;i<n;i++)
        printf("%s", p[i]);
    printf("\n");
    return 0;
}

int main()
{
    int arr[]={321,32,326,18,40};
    min_concat(arr, 5);
    return 0;
}
