/**
    题目：输入两个字符串，从第一字符串中删除第二个字符串中所有的字符
    例如，输入”They are students.”和”aeiou”，则删除之后的第一个字符串变成”Thy r stdnts.”

    Done in 2014.4.25 by B.Y.Sun
*/
#include <stdio.h>
#include <stdlib.h>

void del_chracter(char *s, const char *to_deleted);

int main()
{
    char s[]="They are students.";
    char to_del[]="aoeiu";
    del_chracter(s, to_del);
    printf("deleted string is:\n%s",s);
    return 0;
}

void del_chracter(char *s, const char *to_deleted){
    char ascii[256];
    int i;
    for(i=0;i<256;i++)
        ascii[i]=0;

    while(*to_deleted!=0){
        ascii[*to_deleted]=1;
        to_deleted++;
    }

    char *index, *pos;
    pos=index=s;

    while(*index!='\0'){
        if(ascii[*index]==0){
            *pos++=*index++;
        }else{
            index++;
        }
    }
    *(pos)='\0';
}
