/*
 * main.c
 *
 *  Created on: Nov 30, 2013
 *      Author: bing
 */

#define MAX_NUM 16
extern int biao[MAX_NUM+1][MAX_NUM+1];

int main(){
	int num;
	printf("请输入比赛人数，必须为2的幂次：");
	scanf("%d",&num);
	int result=schedule(1,num);
	if(result<0)
		return -1;

	int i,j;
	printf("编 号 ");
	for(i=1;i<num;i++){

		printf("\t第%d天",i);
	}
	printf("\n");
	for(i=1;i<=num;i++){
		for(j=1;j<=num;j++){
			printf("%-8d",biao[i][j]);
		}
		printf("\n");
	}
	return 0;
}
