/**
    ��Ŀ�����������ַ������ӵ�һ�ַ�����ɾ���ڶ����ַ��������е��ַ�
    ���磬���롱They are students.���͡�aeiou������ɾ��֮��ĵ�һ���ַ�����ɡ�Thy r stdnts.��

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
