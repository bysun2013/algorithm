/*
 * strncpy.c
 *
 *  Created on: Mar 14, 2013
 *      Author: bing
 */

/*
 * strncpy(s,t,n) copies at most n characters of t to s
 *
 * */

#include <stdio.h>
#include <string.h>

#define MAX_CHAR 100
int strncpys(char* s,char* t, int n){

		n=strlen(t)>n? n:strlen(t);
		while(n--)
			*s++=*t++;
		*s='\0';              //I think, this sentence is Good !
		return n;

}

int main(){
	char s[MAX_CHAR];
	char* t="I am Bing, Hello World!";
	strncpys(s,t,6);
	printf("%s\n",s);
	return 0;
}
