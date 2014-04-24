/*
 * expr.c
 *
 *  Created on: Mar 17, 2013
 *      Author: bing
 */

#include <stdio.h>
#include <stdlib.h>
#define MAX 100
//#define DEBUG

int stack[MAX];
int top= -1;

void print_stack(int stack[],int num){
	int i=0;
	for(;i<=num;i++)
		printf("%d\t",stack[i]);
	printf("\n");
}

int main(int argc,char* argv[]){
	printf("Please replace * with '=' ...... \n");

	while(--argc>0 && *++argv)
	{
		if(atoi(*argv)){
			stack[++top]=atoi(*argv);
			continue;
		}
		switch(*argv[0])
		{
		case '=':
			if(top>0)
				stack[top-1]=stack[top-1] * stack[top];
			top--;
			break;
		case '+':
			if(top>0)
			stack[top-1]=stack[top]+stack[top-1];
			top--;
			break;
		case '-':
			if(top>0)
			stack[top-1]=stack[top-1]-stack[top];
			top--;
			break;
		case '/':
			if(top>0)
			stack[top-1]=stack[top-1]/stack[top];
			top--;
			break;
		default:
			printf("Error input,please again!\n");
			return 1;
		}

#ifdef DEBUG
		print_stack(stack,top);
#endif
	}

	if(top==0)
	{
		printf("The result is %d\n",stack[top]);
		return 0;
	}
	else{
		printf("Error occured...,top is %d\n",stack[top]);
		return 1;
	}


}
