/**

��Ŀ������һ��Ӣ�ľ��ӣ���ת�����е��ʵ�˳�򣬵��������ַ���˳�򲻱䡣�����е����Կո��������
Ϊ������������ź���ͨ��ĸһ������

�������롰I am a student.�����������student. a am I����

    Done in 2014.4.5 by B.Y.sun
*/

#include <stdio.h>
#include <stdlib.h>

static void reverse_word(char *begin, char* end){
    char c;
    if(begin==NULL || end ==NULL)
        return;

    while(begin<end){
        c=*begin;
        *begin=*end;
        *end=c;
        begin++;
        end--;
    }
}

int reverse_sentence(char *s){
    char *begin, *end;

    if(s==NULL)
        return 1;
    /* begin reverse the entire sentence */
    begin=end=s;
    while(*end!='\0'){
        end++;
    }
    end--;
    reverse_word(begin, end);

    /* begin reverse every word in the sentence */
    begin=end=s;
    while(*begin != '\0'){
        if(*begin==' '){
            end=++begin;
        }else if(*end==' ' || *end=='\0'){
            reverse_word(begin, --end);
            begin=++end;
        }else{
            end++;
        }
    }

    return 0;
}

#define MAX_NUM 100
int main()
{
    /* �˴�����ʹ�����飬��Ϊ������ջ�У�����ʹ��ָ�룬�ַ����������� */
   char s[MAX_NUM];
   printf("Please enter a sentence:\n");
   gets(s);
   reverse_sentence(s);
   printf("%s", s);
   return 0;
}
