#include <stdio.h>
#include <stdlib.h>
/**
    题目：求1+2+...+n

    要求不能使用乘除法、for、while、if、else、switch、case等关键字以及条件判断语句(A?B:C)

    Done in 2014.4.5 by B.Y.sun
*/

int addition(int n, int *sum);

int main()
{
    int sum=0, n;
    printf("Please enter the value of n: ");
    scanf("%d", &n);

    addition(n, &sum);
    printf("The sum is %d", sum);

    return 0;
}

int addition(int n, int *sum){
    int true=n;
    *sum+=n;
    return (true && addition(n-1, sum));
}
