/*
 * main.c
 *
 *  Created on: Mar 2, 2014
 *      Author: bing
 */


#include <stdio.h>
#include <stdlib.h>
#define MAX_NUM 6
void quick_sort(int a[],int start, int end);

int main(){
	int i;
	int a[MAX_NUM];
	printf("Please enter some integer：（MAX=%d）\t",MAX_NUM);
	for(i=0;i<MAX_NUM;i++)
		scanf("%d",&a[i]);

	quick_sort(a,0,MAX_NUM-1);
	for(i=0;i<MAX_NUM;i++)
		printf("%d\t",a[i]);
	printf("\n");
	return 0;
}
