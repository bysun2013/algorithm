/**
��Ŀ����һ���ַ������ҵ���һ��ֻ����һ�ε��ַ���������abaccdeff�������b��

    �������������2006��google��һ�������⡣

    Done in 2014.4.7
*/

#include <stdio.h>
#include <stdlib.h>


/** ������һ�����������¼ֻ��һ���ַ����ֵ�����ֵ
    �����ͨ���ҵ���������������С��Чֵ���ĵ����ս���ַ�
    �÷����Ƚϸ��ӣ���������ʱ�临�Ӷ�ΪO(n)
*/
#define ASCII_NUM 127
#define MAX_NUM 100
int first_once_character(char *s){
    int count[ASCII_NUM];
    int index[ASCII_NUM];
    char *p=s;
    int i=0;

    memset(count, 0 ,ASCII_NUM*sizeof(int));
    memset(index, -1 ,ASCII_NUM*sizeof(int));

    while(*p!='\0'){
        count[*p]++;

        if(count[*p]==1){
            index[*p]=i;
        }else if(count[*p]>1)
            index[*p]=-1;
        p++;
        i++;
    }

    int min=i, j=0;
    while(j<ASCII_NUM){
        if(index[j]>=0 && min>index[j]){
                min=index[j];
        }
        j++;
    }

    char first_ch=0;
    if(min<i){
        first_ch=*(s+min);
        printf("The first once character is: %c\n", first_ch);
    }else
        printf("There is no the first once character\n");

    return 0;
}

int main()
{
    char s[MAX_NUM];
    printf("Please enter a string:\n");
    scanf("%s", s);

    first_once_character(s);
    return 0;
}
