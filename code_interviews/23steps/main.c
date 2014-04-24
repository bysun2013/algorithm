/**
    ��Ŀ��һ��̨���ܹ��� n �������һ�ο�����1 ����Ҳ������2 ����
    ��һ��Ҫ����������أ���Ȼ�󷨸��鷳�ģ�

    ���ܹ��ж������������������㷨��ʱ�临�Ӷȡ�

    ���ۣ�
        n=1ʱ steps=1��
        n=2ʱ steps=2��
        n>2ʱ steps=steps(n-1)+steps(n-2)
        ʹ�������¼��ÿһ�ε�steps��ʱ�临�Ӷ�ΪO(n)

    Done in 2014.4.13 by B.Y.Sun
*/
#include <stdio.h>
#include <stdlib.h>

int fib(int n)
{
    int *fibo;
    int i,result;
    fibo=(int *)malloc(sizeof(int)* (n+1));

    fibo[1]=1;
    fibo[2]=2;
    for(i=3;i<=n;i++){
        fibo[i]=fibo[i-1]+fibo[i-2];
    }

    result=fibo[n];
    free(fibo);
    return result;
}


int main()
{
    int n, result;
    printf("Please enter the total of steps:\n");
    scanf("%d", &n);
    result=fib(n);
    printf("\nThe kind when there are %d steps is %d\n", n, result);
    return 0;
}
