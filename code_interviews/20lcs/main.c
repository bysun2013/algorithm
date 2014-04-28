/**
    ��Ŀ������ַ���һ�������ַ��������ַ����е�˳�����������һ���ַ������У�
    ���ַ���һ��֮Ϊ�ַ��������Ӵ���

    ע�⣬����Ҫ���Ӵ����ַ���һ�����ַ����������������ַ������С�
    ���дһ�����������������ַ����������ǵ�������Ӵ�������ӡ��������Ӵ���

    ���磺���������ַ���BDCABA��ABCBDAB���ַ���BCBA��BDAB���������ǵ�������Ӵ���
    ��������ǵĳ���4������ӡ����һ���Ӵ���

    Done in 2014.4.28 by B.Y.Sun
*/
#include <stdio.h>
#include <stdlib.h>

enum{
    Init=0,
    Left,
    LeftUp,
    Up
};

int **lcs_len;
char **direct;

int lcs(char *s1, char *s2){
    int len1,len2;
    int i,j;
    char *t=s1;
    len1=len2=0;

    while(*t){
        t++;
        len1++;
    }
    t=s2;
    while(*t){
        t++;
        len2++;
    }
    lcs_len=(int **)malloc(sizeof(int *)*(len1+1));
    for(i=0;i<=len2;i++){
        lcs_len[i]=(int *)malloc(sizeof(int)*(1+len2));
    }

    direct=(char **)malloc(sizeof(char *)*(len1+1));
    for(i=0;i<=len2;i++){
        direct[i]=(char *)malloc(sizeof(char)*(len2+1));
    }
    for(i=0;i<=len1;i++)
        for(j=0;j<=len2;j++){
            direct[i][j]=Init;
            lcs_len[i][j]=0;
        }

    for(i=1;i<=len1;i++)
        for(j=1;j<=len2;j++){
            if(s1[i-1]==s2[j-1]){
                lcs_len[i][j]=lcs_len[i-1][j-1]+1;
                direct[i][j]=LeftUp;
            }else{
            /* change the operator >= or >, print different results */
                if(lcs_len[i-1][j]>=lcs_len[i][j-1]){
                    lcs_len[i][j]=lcs_len[i-1][j];
                    direct[i][j]=Up;
                }else{
                     lcs_len[i][j]=lcs_len[i][j-1];
                     direct[i][j]=Left;
                }
            }
        }
    return lcs_len[len1][len2];
}
static void print_lcs(char *s1, char *s2){
    int len1,len2;
    int i,j;
    char *t=s1;
    len1=len2=0;

    while(*t){
        t++;
        len1++;
    }
    t=s2;
    while(*t){
        t++;
        len2++;
    }

    i=len1,j=len2;
    printf("The longest Common Subsequence is:(reverted)\n");
    while(i!=0 && j!=0){
        switch(direct[i][j]){
        case Left:
            j--;
            break;
        case Up:
            i--;
            break;
        case LeftUp:
            printf("%d:%c ",i,s1[i-1]);
            i--,j--;
            break;
        }
    }
    printf("\n");
}
int main()
{
    char s1[]="BDCABA";
    char s2[]="ABCBDAB";
    lcs(s1, s2);
    print_lcs(s1, s2);
    return 0;
}
