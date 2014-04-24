/**
    题目：一个台阶总共有 n 级，如果一次可以跳1 级，也可以跳2 级。
    （一定要有这个限制呢，不然求法更麻烦的）

    求总共有多少总跳法，并分析算法的时间复杂度。

    讨论：
        n=1时 steps=1；
        n=2时 steps=2；
        n>2时 steps=steps(n-1)+steps(n-2)
        使用数组记录下每一次的steps，时间复杂度为O(n)

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
