/**
    题目：n 个数字（0,1,…,n-1）形成一个圆圈，从数字0 开始，每次从这个圆圈中删除第m 个数字（第一个
    为当前数字本身，第二个为当前数字的下一个数字）。当一个数字删除后，从被删除数字的下一个继续删
    除第m 个数字。

    求出在这个圆圈中剩下的最后一个数字。

    该题有2种方法，一种方法就是循环查找，另一种就是根据数学知识得到一个递归式，时间复杂度为O(n)。
    这里使用比较常用的第一种方法

    Done in 2014.4.12 by B.Y.Sun
*/
#include <stdio.h>
#include <stdlib.h>

#define True 1
#define False 0

int print_arr(int *cr, int n);
int circlar_left(int n, int m);

int main()
{
    int n,m,left;
    printf("Please enter the value of n and m: ");
    scanf("%d%d", &n, &m);
    left=circlar_left(n,m);
    printf("\nThe last one is: %d", left);
    return 0;
}
int circlar_left(int n, int m){
    int *cr;
    int time,i,j;

    cr=malloc(sizeof(int)*n);
    for(i=0;i<n;i++){
        cr[i]=True;
    }

    i=0;
    for(time=1;time<n;time++){
        j=m;
        while(j>0){
            if(cr[i]==True){
                j--;
            }
            i++;
            i=i%n;
        }
        cr[(i+n-1)%n]=False;
        print_arr(cr, n);
    }

    for(i=0;i<n;i++){
        if(cr[i]==True){
            return i;
        }
    }

    return i;
}

int print_arr(int *cr, int n){
    int i;
    printf("The number left is: ");
    for(i=0;i<n;i++){
        if(cr[i]==True){
            printf("%d ", i);
        }
    }
    printf("\n");
    return 0;
}
