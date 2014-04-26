/**
    题目：从扑克牌中随机抽5张牌，判断是不是一个顺子，即这5张牌是不是连续的。
    2-10为数字本身，A为1，J为11，Q为12，K为13，而大小王可以看成任意数字。

    Done in 2014.4.26 by B.Y.Sun
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NUM 5
#define MAX_LEN 20

static int extract(int card[]){
    char s[MAX_LEN];
    char *token = NULL;
    char *p[NUM];
    printf("Please enter five numbers:(King is 0)\n");
    gets(s);
    int i=0;

    p[i++]=strtok(s, " ");
    while((token= strtok(NULL, " "))!=NULL){
        p[i++]=token;
    }
    if(i>NUM){
        printf("To many number...\n");
        return -1;
    }
    for(i=0;i<NUM;i++){
        if(*p[i]<='9' && *p[i]>='0'){
            card[i]=atoi(p[i]);
            continue;
        }
        switch(*p[i]){
        case 'A':
            card[i]=1;
            break;
        case 'J':
            card[i]=11;
            break;
        case 'Q':
            card[i]=12;
            break;
        case 'K':
            card[i]=13;
            break;
        default:
            printf("Error in handle input string.\n");
            return -1;
        }
    }
    return 0;
}
static void sort(int arr[]){
    int i,j;
    for(i=0;i<NUM;i++){
        for(j=i;j<NUM;j++){
            if(arr[i]>arr[j]){
                int tmp=arr[i];
                arr[i]=arr[j];
                arr[j]=tmp;
            }
        }
    }
}
int is_pairs(int arr[]){
    int king=0, index=0;
    int i=0;

    sort(arr);
    while(i<2){
        if(arr[i]==0){
            king++;
            index++;
        }
        i++;
    }
    /* DON'T consider the same card number.*/
    int interval=arr[NUM-1]-arr[index];
    while(index<NUM-1){
        if(arr[index]==arr[index+1])
            return 1;
        index++;
    }
    if(king==0){
        if(interval==NUM-1)
            return 0;
    }else if(king==1){
        if(interval==NUM-2 || interval==NUM-1)
            return 0;
    }else if(king==2){
        if(interval==NUM-3 || interval==NUM-2 || interval==NUM-1)
            return 0;
    }
    return 1;
}

int main()
{
    int err;
    int arr[NUM];

    err=extract(arr);
    if(err<0)
        return -1;

    int result=is_pairs(arr);
    printf("The five number is continuous?  %s\n", result?"False":"True");
    return 0;
}
