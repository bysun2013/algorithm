/**
    ��Ŀ��n �����֣�0,1,��,n-1���γ�һ��ԲȦ��������0 ��ʼ��ÿ�δ����ԲȦ��ɾ����m �����֣���һ��
    Ϊ��ǰ���ֱ����ڶ���Ϊ��ǰ���ֵ���һ�����֣�����һ������ɾ���󣬴ӱ�ɾ�����ֵ���һ������ɾ
    ����m �����֡�

    ��������ԲȦ��ʣ�µ����һ�����֡�

    ������2�ַ�����һ�ַ�������ѭ�����ң���һ�־��Ǹ�����ѧ֪ʶ�õ�һ���ݹ�ʽ��ʱ�临�Ӷ�ΪO(n)��
    ����ʹ�ñȽϳ��õĵ�һ�ַ���

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
