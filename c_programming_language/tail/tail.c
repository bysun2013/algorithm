/*
 * tail.c
 *
 *  Created on: Mar 22, 2013
 *      Author: bing
 */

#include <stdio.h>
#include <stdlib.h>
#define MAXLINES 100
int readlines(char* lineptr[],int maxlines);
void writelines(char* lineptr[],int lines);

int main(int argc,char* argv[]){

	int tline,nlines,line_num_print;
	char *lineptr[MAXLINES],**ptr;

	line_num_print=argc>1? atoi(argv[1]):10;
	printf("please input lines:\n");
	nlines=readlines(lineptr,MAXLINES);
	if(nlines<0){
		printf("Error,Bing!");
		return 1;
	}
//writelines(lineptr,nlines);
	ptr=lineptr;
	tline=nlines-line_num_print;
	for(;tline>0;tline--)
		ptr++;
	writelines(ptr,line_num_print);

	while(nlines--)
		free(lineptr[nlines]);
	return 0;

}
