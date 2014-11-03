#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static int find_n1(int len)
{
	int i=0;
	int n1, n2;

	if(len < 5)
		return 0;

	for(n1=0;n1<len;n1++){
		n2 = len - 2*n1 + 2;
		if(n2 < n1)
			break;
	}
	n1--;
	return n1;
}
int main()
{
	int i, j, n1, n2, len;
	char s[80];
	
	while(scanf("%s", s) != EOF){
		int i, offset = 0, lastline;
		len = strlen(s);
		n1 = find_n1(len);
		n2 = len + 2 - 2*n1; 
		for(i=0;i<n1-1;i++){
			printf("%c",s[offset]);
			for(j=0;j<n2-2;j++){
				printf(" ");
			}
			printf("%c\n",s[len-1-offset]);
			offset++;
		}
		lastline = len-1-offset;
		while(offset <= lastline)
			printf("%c", s[offset++]);
		printf("\n");
	}
}

