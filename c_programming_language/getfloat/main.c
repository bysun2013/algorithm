/*
 * main.c
 *
 *  Created on: Mar 11, 2013
 *      Author: bing
 */

#include <stdio.h>
extern buf[];
int getfloat(float *pn);
int main(){
	int sign;
	float n;
printf("Please input a float:\n");
sign=getfloat(&n);
if(sign!=0)
	printf("the number is %f \n",n);
else{
	printf("Error:input is bad!");
	printf("The buffer is %s",buf);
	}
return 0;
}
