/**
    ��Ŀ������һ������n��������к�Ϊn�����������С�
    ��������15������1+2+3+4+5=4+5+6=7+8=15���������3����������1-5��4-6��7-8��

    Done in 2014.4.14 by B.Y.Sun
*/
#include <stdio.h>
#include <stdlib.h>

int sum_is_n(int expected){
    int i=1, j=2;
    int sum=3;

    printf("The sequence of %d is:\n", expected);

    while(i<=expected/2){
        if(sum<expected){
            j++;
            sum+=j;
        }else if(sum == expected){
            printf("%d-%d ", i, j);
            j++;
            sum+=j;
        }else{
            sum-=i;
            i++;
        }
    }
    return 0;
}

int main()
{
    int expected;
    printf("Please enter a value:\n");
    scanf("%d", &expected);
    sum_is_n(expected);
    return 0;
}
