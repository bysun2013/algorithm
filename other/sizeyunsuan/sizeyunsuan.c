/*
 * sizeyunsuan.c
 *
 *  Created on: Nov 28, 2013
 *      Author: bing
 *
 *      实现简单的四则运算，加减乘除；
 *      @num为输入的数字；
 *      @op为运算符，要求最后一个运算符为空格；
 *      @n为所输入数字的个数
 */

#include <stdio.h>

int sizeyunsuan(int *num, char* op, int n){
	int sign=1;
	int i,j;
	int left=0, right=*num;
	for(i=0;i<n;i++){
		switch(op[i]){
		case '+':
			left=left+sign*right;
			sign=1;
			right=*++num;
			break;
		case '-':
			left=left+sign*right;
			sign= -1;
			right=*++num;
			break;
		case '*':
			right=right*(*(++num));
			break;
		case '/':
			if(*(num+1)==0){
				printf("除数不能为0！");
				return -1;
			}
			right=right/(*(++num));
			break;
		default:
			break;
		}
	}
		return left+sign*right;
}



