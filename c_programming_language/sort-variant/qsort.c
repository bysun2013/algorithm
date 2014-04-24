/*
 * qsort.c
 *
 *  Created on: Mar 26, 2013
 *      Author: bing
 *
 */

#include <stdio.h>
#include <string.h>
#include "readlines.h"
#define MAXLINE 1000



int main(int argc,char* argv[]){
	char *lineptr[MAXLINE];
	int nlines,number=0,revert=0,noncase=0;
	int (*cmp)(char* m,char* n);
	cmp=strcmp;
	while(--argc>0 && (*++argv)[0]=='-'){
		while(*++argv[0]){
			switch(*argv[0]){
			case 'n':
				number=1;
				cmp=numcmp;
				break;
			case 'r':
				revert=1;
				break;
			case 'f':
			    noncase=1;
			    cmp=strcasecmp;
			    break;
			default:
				printf("Wrong arguement...");
				return 1;
			}
		}
	}
	if(argc!=0){
		printf("Usage: sort -n -r \n");
		return 1;
	}
	if((nlines=readlines(lineptr,MAXLINE))>=0){
		if(!revert)
			qsort_s(lineptr,0,nlines-1,cmp);
		else
			qsort_r(lineptr,0,nlines-1,cmp);
		writelines(lineptr,nlines);
		return 0;
	}else{
		printf("Error occured !");
		return 1;
	}

}

