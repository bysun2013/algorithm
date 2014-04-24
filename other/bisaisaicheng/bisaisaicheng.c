/*
 * bisaisaicheng.c
 *
 *  Created on: Nov 30, 2013
 *      Author: bing
 *
 *      每个选手必须与其他所有选手进行一次比赛，且每位选手每天必须比赛一场
 *      利用分治算法来简化日程的安排，一分为二的方法
 *    例如：
 *      请输入比赛人数，必须为2的幂次：8
		编 号 	第1天	第2天	第3天	第4天	第5天	第6天	第7天
		1       2       3       4       5       6       7       8
		2       1       4       3       6       5       8       7
		3       4       1       2       7       8       5       6
		4       3       2       1       8       7       6       5
		5       6       7       8       1       2       3       4
		6       5       8       7       2       1       4       3
		7       8       5       6       3       4       1       2
		8       7       6       5       4       3       2       1
 *
 */
#include <stdio.h>

#define MAX_NUM 16
int biao[MAX_NUM+1][MAX_NUM+1];

int schedule(int begin,int num){

	int i,j,k=num;
/*检查比赛人数是否为2的幂次*/
	while(k%2==0)
		k=k/2;
	if(k!=1){
		printf("比赛人数必须是2的幂次！");
		return -1;
	}
/* 此处开始利用分治算法，递归解决问题*/
	if(num==2){
		biao[begin][1]=begin;
		biao[begin][2]=begin+1;
		biao[begin+1][1]=begin+1;
		biao[begin+1][2]=begin;
		return 0;
	}

	schedule(begin,num/2);
	schedule(begin+num/2,num/2);
	/*填充右下半部*/
	for(i=begin+num/2;i<begin+num;i++){
		for(j=num/2+1;j<=num;j++)
			biao[i][j]=biao[i-num/2][j-num/2];
	}
	/*填充右上半部*/
	for(i=begin;i<begin+num/2;i++){
		for(j=num/2+1;j<=num;j++)
			biao[i][j]=biao[i+num/2][j-num/2];
	}
	return 0;
}
