/*
 * readline.c
 *
 *  Created on: Mar 22, 2013
 *      Author: bing
 */

#include <string.h>
#include <stdio.h>
#define MAX_LEN 500

char* malloc(int len);

static int getline_(char* line,int lim){
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
	char line[MAX_LEN],*p;
	int len,nlines=0;
	while((len=getline_(line,MAX_LEN))>1){
		if(nlines>=maxlines||(p=(char*)malloc(len+1))==NULL)
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
