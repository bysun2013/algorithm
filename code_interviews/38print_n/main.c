/**
    ��Ŀ����������n����˳�������1����nλ10��������
    ��������3�������1��2��3һֱ������3λ����999��

    ����������һ��������˼����Ŀ���������ܼ򵥣���ʵ����ȴ�в��ٵ�������
    ���������ϸ����������⣬����ע�⵽����û�й涨n�ķ�Χ��
    ������������nλ����ʱ���ǲ����п������������������Ͷ��������

    Done in 2014.4.25 by B.Y.Sun
*/
#include <stdio.h>
#include <stdlib.h>
static char *num;
void build_sub(char *s){
    int i;
    if(*s=='\0'){
        char *tmp=num;
        while(*tmp=='0')
            tmp++;
        printf("%s ", tmp);
        return;
    }
    for(i=0;i<10;i++){
        s[0]='0'+i;
        build_sub(s+1);
    }
}

void print_n(int digit){
    num=malloc(sizeof(char)*(digit+1));
    int i=0;
    for(;i<digit;i++){
        num[i]='0';
    }
    num[digit]='\0';
    printf("The number from 0 to N-digit:\n");
    build_sub(num);
}

int main()
{
    int digit;
    printf("Please enter a number: ");
    scanf("%d", &digit);
    print_n(digit);
    return 0;
}
