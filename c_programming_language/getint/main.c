/*
 * main.c
 *
 *  Created on: Mar 11, 2013
 *      Author: bing
 */

#include <stdio.h>
extern buf[];
int getint();
int main(){
	int n,sign;
printf("Please input a int:\n");
sign=getint(&n);
if(sign!=0)
	printf("the number is %d \n",n);
else{
	printf("Error:input is bad!");
	printf("The buffer is %s",buf);
	}
return 0;
}
