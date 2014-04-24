/**
    ��Ŀ������Fibonacci�������£�

        n=0     f(n)= 0
        n=1     f(n)= 1
        n>=2    f(n)= f(n-1)+f(n-2)

    ����n�������ķ���������еĵ�n�

    Done in 2014.4.12 by B.Y.Sun

    PS:��ѧûѧ�ã����������е�O��log(n))�ķ���...
*/
#include <stdio.h>
#include <stdlib.h>

int fib(int n);

int main()
{
    int n, result;
    printf("Please enter a number:\n");
    scanf("%d", &n);
    result=fib(n);
    printf("\nThe fib of %d is %d.\n", n, result);
    return 0;
}

int fib(int n)
{
    int *fibo;
    int i,result;
    fibo=(int *)malloc(sizeof(int)* (n+1));

    fibo[0]=0;
    fibo[1]=1;
    for(i=2;i<=n;i++){
        fibo[i]=fibo[i-1]+fibo[i-2];
        printf("fib[%d] = %d\n", i, fibo[i]);
    }

    result=fibo[n];
    free(fibo);
    return result;
}
