/*
 * readlines.h
 *
 *  Created on: Mar 26, 2013
 *      Author: bing
 */

#ifndef READLINES_H_
#define READLINES_H_


#define MAXCHAR	2000          //generally placed in *.h


int numcmp(char* m,char* n);

static int getline_(char* line,int lim);

int readlines(char* lineptr[],int maxlines);

void writelines(char* lineptr[],int lines);

void qsort_s(char* s[],int left,int right,int (*cmp)(char*,char*));
void qsort_r(char* s[],int left,int right,int (*cmp)(char*,char*));

void swap(char* s[],int i,int j);


#endif /* READLINES_H_ */
