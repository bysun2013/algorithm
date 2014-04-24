/*
 * readline.c
 *
 *  Created on: Mar 26, 2013
 *      Author: bing
 */


#include <string.h>
#include <stdio.h>

#define MAXCHAR	2000          //generally placed in *.h

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
int readlines(char* lineptr[],char storage[][MAXCHAR],int maxlines){
	char line[MAXCHAR];
	int len,nlines=0;
	while((len=getline_(line,MAXCHAR))>1){
		if(nlines>=maxlines||len>=MAXCHAR)
			return -1;
		line[len-1]='\0';
		strcpy(*storage,line);
//printf("%s",p);
		lineptr[nlines++]=*storage++;
	}
	return nlines;
}

void writelines(char* lineptr[],int lines){
	printf("The lines just is follow: \n");
	while(lines--)
		printf("%s\n",*lineptr++);
}
