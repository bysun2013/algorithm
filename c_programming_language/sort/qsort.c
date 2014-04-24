/*
 * qsort.c
 *
 *  Created on: Mar 26, 2013
 *      Author: bing
 *      contrasted with before,this program rewrite readlines() to store
 *      data in a fixed-size array,with some waste of memory...
 *      Just for exercise , P110 of <<The C programming Language>> ||
 */

#include <stdio.h>
#include <string.h>
#define MAXLINE 100
#define MAXCHAR	2000
int readlines(char* lineptr[],char storage[][MAXCHAR],int maxlines);
void writelines(char* lineptr[],int lines);
void qsort(char* s[],int left,int right);

int main(){
	char *lineptr[MAXLINE];
	char storage[MAXLINE][MAXCHAR];
	int nlines;
	if((nlines=readlines(lineptr,storage,MAXLINE))>=0){
		qsort(lineptr,0,nlines-1);
		writelines(lineptr,nlines);
		return 0;
	}else{
		printf("Error occured !");
		return 1;
	}

}

void qsort(char* s[],int left,int right){
	int last,i;
	void swap(char* s[],int i,int j);

	if(left>=right){
//printf("Left must be less than right!");
		return;
	}
	swap(s,left,(left+right)/2);
	last=left;
	for(i=left+1;i<=right;i++)
		if(strcmp(s[i],s[left])<0)
			swap(s,i,++last);
	swap(s,last,left);
	qsort(s,left,last-1);
	qsort(s,last+1,right);

}


void swap(char* s[],int i,int j){
	char* temp;
	temp=s[i];
	s[i]=s[j];
	s[j]=temp;
}
