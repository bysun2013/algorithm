/**
    ��Ŀ������һ����������������Ķ����Ʊ�����ж��ٸ�1��
    ��������10������������Ʊ�ʾΪ1010��������1��������2��

    Done in 2014.4.13 by B.Y.Sun
*/
#include <stdio.h>
#include <stdlib.h>

/* ������Ϊ����ʱ������� */
int numof1_rc1(int n){
    int count=0;

    while(n){
        if((n & 1) ==1)
            count++;
        n=n>>1;
    }
    return count;
}

/* �ɴ����� */
int numof1_rc2(int n){
    int count=0;
    unsigned int flag=1; /* ע���������ͣ�������unsigned */
    while(flag){
        if(n & flag)
            count++;
        flag = flag<<1;
    }
    return count;
}
/* ��һ��������ȥ1���ٺ�ԭ�����������㣬��Ѹ��������ұ�һ��1���0 */
int numof1_rc3(int n){
    int count=0;
    while(n){
        n=n & (n-1);
        count++;
    }
    return count;

}

int main()
{
    int n;
    int result;
    for(n=-10;n<=10;n++){
        result=numof1_rc3(n);
        printf("The number of 1 in %d is %d\n", n, result);
    }

    return 0;
}
