/**
    ��Ŀ�������ַ���������ת���������ַ���ǰ������ɸ��ַ��ƶ����ַ�����β����
    ����ַ���abcdef����ת2λ�õ��ַ���cdefab����ʵ���ַ�������ת�ĺ�����

    Ҫ��ʱ��Գ���Ϊn���ַ��������ĸ��Ӷ�ΪO(n)�������ڴ�ΪO(1)

    DONE in 2014.4.13 by B.Y.Sun
*/
#include <stdio.h>
#include <stdlib.h>
/**
�÷���ʹ��O(1)���ڴ棬�Ե��ַ����ĳ���len����n����������ʱ��
ʱ��ʱ������ʱ�������ַ�����
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

/* ������(start, end) ��������start��������end */
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
    �������ȶ� X ��Y ���ηֱ���з�ת�������������ܵõ�XTYT��
    �����ٶ�XTYT ���з�ת�������õ�(XTYT)T=(YT)T(XT)T=YX
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
