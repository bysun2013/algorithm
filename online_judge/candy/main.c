/**
给从左至右排好队的小朋友们分糖果，
要求：
1.每个小朋友都有一个得分，任意两个相邻的小朋友，得分较高的所得的糖果必须大于得分较低的，相等则不作要求。
2.每个小朋友至少获得一个糖果。
求，至少需要的糖果数。
*/

#include <stdio.h>
#include <stdlib.h>

static int sum(int b[], int n)
{
    int i, sum = 0;
    for(i=0;i<n;i++)
        sum += b[i];

    return sum;
}

static int candy(int a[], int n)
{
    int i;
    int *b;
    int total;

    b = (int *)malloc(sizeof(int)*n);

    for(i=0;i<n;i++){
        b[i] = 1;
    }

    for(i=1;i<n;i++){
        if(a[i] > a[i-1])
            b[i] = b[i-1] + 1;
    }

    for(i=n-1;i>0;i--){
        if(a[i-1] > a[i]){
            int tmp;
            tmp = b[i] + 1;
            if(b[i-1] < tmp)
                b[i-1] = tmp;
        }
    }

    total = sum(b, n);
    return total;
}

int main()
{
    int n, *a;

    while(scanf("%d", &n) != EOF){
        int total, i;
        a = (int *)malloc(sizeof(int) * n);
        for(i=0;i<n;i++)
            scanf("%d", &a[i]);
        total = candy(a, n);
        printf("%d\n", total);
    }

    return 0;
}
