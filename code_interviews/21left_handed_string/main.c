/**
    题目：定义字符串的左旋转操作：把字符串前面的若干个字符移动到字符串的尾部。
    如把字符串abcdef左旋转2位得到字符串cdefab。请实现字符串左旋转的函数。

    要求时间对长度为n的字符串操作的复杂度为O(n)，辅助内存为O(1)

    DONE in 2014.4.13 by B.Y.Sun
*/
#include <stdio.h>
#include <stdlib.h>
/**
该方法使用O(1)的内存，对当字符串的长度len不是n的整数倍的时候，
时好时坏，暂时放弃这种方法，
*/
void left_handed_rc2(char *s, int n){
    char *cp=s;
    int i,j,len=0;
    char tmp;

    while(*cp!='\0'){
        len++;
        cp++;
    }

    if(n>=len)
        n=n%len;
    if(n==0)
        return;

    if(len%n!=0){
        tmp=s[0];
        j=n;
        for(i=0;i<n;i++){
            while(j<len){
                s[j-n]=s[j];
                j+=n;
            }
            s[j-n]=s[j%len];
            j=j%len;
            if(j==0){
                /* NEED DO SOMETHING SPECIAL */
            }
            printf("%s\n", s);
        }
        s[j+len-n]=tmp;
    }else{
        for(i=0;i<n;i++){
            tmp=s[i];
            j=i;
            while(j<len){
                s[j-n]=s[j];
                j+=n;
            }
            s[j-n]=tmp;
        }
    }
    return;
}

/* 开区间(start, end) ，即包含start，不包含end */
static void reverse_string(char *start, char *end){
    char c;
    if(start==end || start==NULL)
        return;
    end--;
    while(start<end){
        c=*start;
        *start=*end;
        *end=c;
        start++;
        end--;
    }
}
/**
    我们首先对 X 和Y 两段分别进行翻转操作，这样就能得到XTYT。
    接着再对XTYT 进行翻转操作，得到(XTYT)T=(YT)T(XT)T=YX
*/
void left_handed_rc1(char *s, int n){
    char *first_start=s, *first_end=s, *second_start, *second_end=s;
    int len=0;

    if(n==0 || s==NULL)
        return;

    while(*second_end!='\0'){
        len++;
        second_end++;
    }

    if(n>=len)
        n=n%len;

    first_end=first_start+n;
    second_start=first_end;

    reverse_string(first_start, first_end);
    reverse_string(second_start, second_end);
    reverse_string(first_start, second_end);
}

int main()
{
    int i=0,n=12;
    for(;i<=n;i++){
        char s[]="abcdefghijkl";
        printf("The origin string is: %s\n", s);
        left_handed_rc1(s, i);
        printf("The left handed string is:%s\n\n", s);
    }

    return 0;
}
