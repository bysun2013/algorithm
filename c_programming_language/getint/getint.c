#include <ctype.h>
#include <stdio.h>
int getch(void);
void ungetch(int);

/* getint: get next integer from input into *pn */

int getint(int *pn){
	int c,sign;

	while(isspace(c=getch()))
	;
	if(!isdigit(c) && c!=EOF && c!='+'&& c!='-'){
		ungetch(c);
		return 0;
	}
	sign=(c=='-')?-1:1;
	if(c=='+'|| c=='-')
		c=getch();
	/*
	 * Fix Bug: '-'后不是digit的话，返回0；
	 * */
	if(!isdigit(c)){
		ungetch(c);
		return 0;
	}
	for(*pn=0;isdigit(c);c=getch()){
		*pn=10*(*pn)+(c-'0');
	}
	*pn=(*pn)*sign;
	if(c!=EOF)
		ungetch(c);
	return c;
		
}


