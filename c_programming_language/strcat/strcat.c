/*
 * strcat.c
 *
 *  Created on: Mar 14, 2013
 *      Author: bing
 */

#include <stdio.h>
#define MAX_CHAR 100

/*
 * strcat(s,t) copies the string t to the end of s.
 * s MUST BE big enough !
 *
 * */
void strcats(char* s,char* t){
	while(*s!='\0')
		s++;
	while((*s++=*t++)!='\0')
		;
}

int main(){
	char s[MAX_CHAR]="Hello,World";
	char* t=",Bing";
	printf("Before Strcat() is %s\n",s);

	strcats(s,t);
	printf("After Strcat() is %s\n",s);
	return 0;
}
