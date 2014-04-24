/**

题目：输入一个英文句子，翻转句子中单词的顺序，但单词内字符的顺序不变。句子中单词以空格符隔开。
为简单起见，标点符号和普通字母一样处理。

例如输入“I am a student.”，则输出“student. a am I”。

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
    /* 此处必须使用数组，因为数组在栈中；若是使用指针，字符串在数据区 */
   char s[MAX_NUM];
   printf("Please enter a sentence:\n");
   gets(s);
   reverse_sentence(s);
   printf("%s", s);
   return 0;
}
