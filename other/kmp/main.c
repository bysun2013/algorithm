/*
* KMPÀ„∑®
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int* getnext(const char* p)
{
    int i = 0, j = -1;
    int length;
    int* next;
    if(!p)
        return NULL;

    length = strlen(p);

    next = malloc(sizeof(int)*length);
    next[0] = -1;

    while(i < length - 1){
        if( j == -1 || p[i] == p[j]){
            i++;
            j++;
            if(p[i] == p[j])
                next[i] = next[j];
            else
                next[i] = j;
        } else {
            j = next[j];
        }
    }

    for(i = 0; i < length; i++)
        printf("next[%d] = %d\n", i, next[i]);

    return next;
}

int kmp(const char* s, const char* p)
{
    int i = 0, j = 0;
    int len_s = strlen(s);
    int len_p = strlen(p);
    int *next;

    next = getnext(p);

    if(!next)
        return -1;

    while(i < len_s && j < len_p){
        if(j == -1 || s[i] == p[j]){
            i++;
            j++;
        }else
            j = next[j];
    }

    if(j == len_p){
        printf("YES, match from %d\n", i - j);
    }else{
        printf("NO!\n");
    }

    if(next)
        free(next);

    return 0;
}

#define MAX_LENGTH 100
int main()
{
    char s[MAX_LENGTH];
    char p[MAX_LENGTH];
    int err;

    printf("Please enter match string:\n");
    scanf("%s", s);
    printf("Please enter pattern string:\n");
    scanf("%s", p);

    err = kmp(s, p);

    return err;
}
