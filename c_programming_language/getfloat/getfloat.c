#include <ctype.h>
#include <stdio.h>
int getch(void);
void ungetch(int);

/*
 * getfloat: get next float from input into *pn
 *
 * */

int getfloat(float *pn){
	int sign,decimal_length=1;
	float c,fraction=0;

	while(isspace(c=getch()))
	;
	if(!isdigit(c) && c!=EOF && c!='+'&& c!='-'){
		ungetch(c);
		return 0;
	}
	sign=(c=='-')?-1:1;
	if(c=='+'|| c=='-')
		c=getch();

	if(!isdigit(c)){
		ungetch(c);
		return 0;
	}
	for(*pn=0;isdigit(c);c=getch()){
		*pn=10*(*pn)+(c-'0');
	}
	if(c=='.')
		c=getch();
	else
		goto no_decimal;
	for(;isdigit(c);c=getch()){
		fraction=fraction*10+(c-'0');
		decimal_length*=10;
	}
	if(decimal_length>0)
		fraction=fraction/decimal_length;
no_decimal:
	*pn=(*pn+fraction)*sign;
	if(c!=EOF)
		ungetch(c);
	return c;

}


