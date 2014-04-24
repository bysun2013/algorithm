/*
 * getch.c
 *
 *  Created on: Mar 11, 2013
 *      Author: bing
 */

/*
 * getch.c
 *
 *  Created on: Mar 11, 2013
 *      Author: bing
 */
#include <stdio.h>
#define BUFSIZE	10
int bufp=0;
char buf[BUFSIZE];

int getch(void){
	return(bufp>0)?buf[--bufp]:getchar();
}

void ungetch(int c){
	if(bufp>=BUFSIZE)
		printf("ungetch: too much character");
	else
		buf[bufp++]=c;
}
