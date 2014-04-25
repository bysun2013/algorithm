/**
    ��Ŀ�����ǰ�ֻ�������� 2��3��5��������������Ugly Number����
    ����6��8���ǳ�������14���ǣ���Ϊ����������7��ϰ�������ǰ�1�����ǵ�һ��������
    �󰴴�С�����˳��ĵ�1500��������

    ����������һ���������Ϲ�Ϊ�����������⣬��˵Google�������ù�����⡣

    Done in 2014.4.25 by B.Y.Sun
*/
#define MAX_NUM 1500

#include <stdio.h>
#include <stdlib.h>

static void print(int ugly[], int n);
int get_ugly_num(int index);

int main()
{
    int index;
    printf("Please input index:\n");
    scanf("%d", &index);
    int ugly=get_ugly_num(index);
    printf("The %dth ugly number is %d.\n", index, ugly);
    return 0;
}

int get_ugly_num(int index){
    int ugly[MAX_NUM]={1};

    int i;
    int two_min_index=0, three_min_index=0, five_min_index=0;

    int two_min_ugly, three_min_ugly, five_min_ugly;

    for(i=1;i<MAX_NUM;i++){
        int cur_min_ugly;
        two_min_ugly=ugly[two_min_index]*2;
        three_min_ugly=ugly[three_min_index]*3;
        five_min_ugly=ugly[five_min_index]*5;
        cur_min_ugly=(two_min_ugly<three_min_ugly)?
            (two_min_ugly<five_min_ugly? two_min_ugly:five_min_ugly):
                (three_min_ugly<five_min_ugly? three_min_ugly:five_min_ugly);

        ugly[i]=cur_min_ugly;

        int twi=two_min_index, thi=three_min_index, fii=five_min_index;

        while(ugly[twi]<=cur_min_ugly/2){
            twi++;
        }
        two_min_index=twi;

        while(ugly[thi]<=cur_min_ugly/3){
            thi++;
        }
        three_min_index=thi;

        while(ugly[fii]<=cur_min_ugly/5){
            fii++;
        }
        five_min_index=fii;
    }
    print(ugly, index);
    return ugly[index-1];
}

static void print(int ugly[], int n){
    int i=0;
    printf("\nThe ugly is:\n");
    for(;i<n;i++){
        printf("%d ",ugly[i]);
    }
    printf("\n");
}
