/**
    题目：输入一个整数，求该整数的二进制表达中有多少个1。
    例如输入10，由于其二进制表示为1010，有两个1，因此输出2。

    Done in 2014.4.13 by B.Y.Sun
*/
#include <stdio.h>
#include <stdlib.h>

/* 当输入为负数时，会出错 */
int numof1_rc1(int n){
    int count=0;

    while(n){
        if((n & 1) ==1)
            count++;
        n=n>>1;
    }
    return count;
}

/* 可处理负数 */
int numof1_rc2(int n){
    int count=0;
    unsigned int flag=1; /* 注意整数类型，必须是unsigned */
    while(flag){
        if(n & flag)
            count++;
        flag = flag<<1;
    }
    return count;
}
/* 把一个整数减去1，再和原整数做与运算，会把该整数最右边一个1变成0 */
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
