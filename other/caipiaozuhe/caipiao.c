/*
 * caipiao.c
 *
 *  Created on: Dec 3, 2013
 *      Author: bing
 *
 * 	彩票组合规则：不重复且没有顺序
 *
 * 	正是因为它的规则，才能使用这样的算法
 *  PS：递归还是少用的好，它对内存的使用比较大，很容易出现内存溢出
 */

#include <stdio.h>
#define MAXN 29
#define NUM 7

int lottery[NUM];
int combine(int limit, int num);

int main(){

	combine(MAXN, NUM);
	return 0;
}

int combine(int limit, int num)
{
	int i,j;
	for(i=limit;i>=num;i--)
	{
		lottery[num-1]=i;
		if(num>1)
		{
			combine(i-1,num-1);
		}else if(num==1)
			{
				for(j=NUM-1;j>=0;j--)
					printf("\t%d",lottery[j]);
			}
			getchar();
			printf("\n");
	}
	return 0;
}
