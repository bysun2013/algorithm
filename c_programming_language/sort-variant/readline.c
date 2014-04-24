/*
 * readline.c
 *
 *  Created on: Mar 26, 2013
 *      Author: bing
 */


#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#include "readlines.h"


int getline_(char* line,int lim){
	int i,c;
	for(i=0;i<lim-1&&(c=getchar())!=EOF&&c!='\n';i++)
		line[i]=c;
	if(c=='\n'){
		line[i]=c;
		i++;
	}
	line[i]='\0';
	return i;

}
int readlines(char* lineptr[],int maxlines){
	char line[MAXCHAR],*p;
	int len,nlines=0;
	while((len=getline_(line,MAXCHAR))>1){
		if(nlines>=maxlines||(p=malloc(len+1))==NULL)
			return -1;
		line[len-1]='\0';
		strcpy(p,line);
//printf("%s",p);
		lineptr[nlines++]=p;
	}
	return nlines;
}

void writelines(char* lineptr[],int lines){
	printf("The lines just is follow: \n");
	while(lines--)
		printf("%s\n",*lineptr++);
}




void qsort_s(char* s[],int left,int right,int (*cmp)(char*,char*)){

	int last,i;
	void swap(char* s[],int i,int j);

	if(left>=right)
		return;

	swap(s,left,(left+right)/2);
	last=left;
	for(i=left+1;i<=right;i++)
		if((*cmp)(s[i],s[left])<0)
			swap(s,i,++last);
	swap(s,last,left);
	qsort_s(s,left,last-1,cmp);
	qsort_s(s,last+1,right,cmp);

}

void qsort_r(char* s[],int left,int right,int (*cmp)(char*,char*)){

	int last,i;
	void swap(char* s[],int i,int j);

	if(left>=right)
		return;

	swap(s,left,(left+right)/2);
	last=left;
	for(i=left+1;i<=right;i++)
		if((*cmp)(s[i],s[left])>0)
			swap(s,i,++last);
	swap(s,last,left);
	qsort_r(s,left,last-1,cmp);
	qsort_r(s,last+1,right,cmp);

}

void swap(char* s[],int i,int j){
	char* temp;
	temp=s[i];
	s[i]=s[j];
	s[j]=temp;
}

int numcmp(char* m,char* n){
	int i,j;
	i=atoi(m);
	j=atoi(n);
	if(i>j)
		return 1;
	else if(i<j)
		return -1;
	else
		return 0;
}

