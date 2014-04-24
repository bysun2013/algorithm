/*
 * main.c
 *
 *  Created on: Nov 28, 2013
 *      Author: bing
 */


#include <stdio.h>

extern int sizeyunsuan(int *num, char* op, int n);
int test();

int main(){
	return test();
}

int test(){
	int i,num[4]={5,4,2,1};
	char *op="+/- ";
	int result=sizeyunsuan(num,op,4);
	if(result==-1)
		return result;
	printf("运算式为: ");
	for(i=0;i<4;i++){
		printf("%d%c",num[i],op[i]);
	}
	printf("\n");
	printf("运算结果为：%d",result);

	return 0;
}
