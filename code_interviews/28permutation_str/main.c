/**
��Ŀ��
    ����һ���ַ�������ӡ�����ַ������ַ����������С�
    ���������ַ���abc����������ַ�a��b��c�������г����������ַ�����
        abc��acb��bac��bca��cab��cba

    Done in 2014.4.20 by B.Y.Sun

    PS:����Ƚ�������⣬��ϸ���ǽ����Ĺ��̣�
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
