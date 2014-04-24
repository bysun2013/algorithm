/*
 * strend.c
 *
 *  Created on: Mar 14, 2013
 *      Author: bing
 */

#include <stdio.h>
#include <string.h>
/*
 * strend(s,t) returns 1 if the string t occurs at the
 * end of the string s, and zero otherwise.
 *
 * */
int strend(char* s,char* t){
	int i=strlen(t);
	int j=strlen(s);
	int k=j-i;
	if(k<0)
		return 0;
	while(k--)
		s++;
	while(*s++==*t++)
		if(*s=='\0')
			return 1;
	return 0;

}

int main(int argc,char* argv[]){
	char* s="hello,world!";
	char* t=argv[1];
	if(strend(s,t))
		printf("T occur at the end of S !");
	else
		printf("T NOT occur at the end of S !");
	return 0;
}
