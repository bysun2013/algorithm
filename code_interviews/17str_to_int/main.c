/**
    ��Ŀ������һ����ʾ�������ַ������Ѹ��ַ���ת������������������������ַ���"345"�����������345��
    ֧�ְ˽��ƣ�ʮ���ƣ�ʮ�����ƣ�֧��������

    ����Ŀ���ѣ�����ע��ϸ�ڣ��������ķ���

    Done in 2014.4.12 by B.Y.Sun

*/
#include <stdio.h>
#include <stdlib.h>

#define MAX_NUM 20

static int str_to_int(const char *s, int *dec);

int main()
{
    int result;
    char num[MAX_NUM];

    printf("Please enter a string:\n");
    scanf("%s", num);

    if(str_to_int(num, &result)<0)
        return -1;
    printf("The num is %d", result);
    return 0;
}

static int str_to_int(const char *s, int *dec){
    int result=0;
    int sign=1;
    const char *t=s;

    if(!s){
        printf("Error: The string is NULL\n");
        return -1;
    }

    if(*t=='+')
        t++;
    else if(*t=='-'){
        sign=-1;
        t++;
    }

    if(*t=='0' && *(t+1) !='x'){
        while(t){
            if(*t>'7' || *t <'0')
                break;
            result=result*8+(*t-'0');
            t++;
        }
    }else if(*t=='0' &&(*(t+1) =='x' || *(t+1) =='X')){
        t=t+2;
        while(t){
            if(!((*t<='9' && *t >='0') || (*t<='f' && *t>='a') || (*t<='F' && *t>='A')))
                break;
            if(*t<='9' && *t >='0')
                result=result*16+(*t-'0');
            else if(*t<='f' && *t>='a')
                result=result*16+(*t-'a')+10;
            else
                result=result*16+(*t-'A')+10;
            t++;
        }
    }else{
        while(t){
            if(*t>'9' || *t <'0')
                break;
            result=result*10+(*t-'0');
            t++;
        }
    }

    result=result*sign;
    *dec=result;
    return 0;

}
