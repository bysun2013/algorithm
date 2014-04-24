/*
 * exchange.c
 *
 *  Created on: Nov 30, 2013
 *      Author: bing
 */

#include <stdio.h>
#define MAXN 10

static int value[MAXN]={10000,5000,2000,1000,500,200,100,50,20,10};
int num[MAXN]={0};

int exchange(double m){
	int n=m*100, i;

	for(i=0;i<MAXN;i++)
		if(n>value[i])
			break;

	while(n>0 && i<MAXN){
		if(n>=value[i]){
			num[i]++;
			n-=value[i];
		}else if(n>=5 && n<10){
			num[MAXN-1]++;
			break;
		}else
			i++;
	}
	return 0;
}

int main(){
	double money;
	int i;
	printf("请输入要找补的零钱： ");
	scanf("%lf",&money);
	exchange(money);
	for(i=0;i<MAXN;i++){
		if(num[i]>0)
			printf("面额为%6.2f：%d张\n",(float)value[i]/100,num[i]);
	}
}
