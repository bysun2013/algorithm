#include <stdio.h>
#include <string.h>
#include <stdlib.h>

static void print_lcs(const char *s1, const char *memo, int len1, int len2, int i, int j)
{
	if(!i || !j)
		return;

	if(*(memo+i*len2+j) == 'y'){
		print_lcs(s1, memo, len1, len2, i-1, j-1);
		printf("%c", s1[i-1]);
	}else if(*(memo+len2*i+j) == 'l'){
		print_lcs(s1, memo, len1, len2, i, j-1);
	}else
		print_lcs(s1, memo, len1, len2, i-1, j);
}

static void print_array_int(int *lcs_len, int len1, int len2){
	int i,j;

	printf("The lcs length is:\n");
	for(i=0;i<=len1;i++){
		for(j=0;j<=len2;j++){
			printf("%6d ",*(lcs_len+len2*i+j));
		}
		printf("\n");
	}
}
static void print_array_char(char *memo, int len1, int len2){
	int i,j;

	printf("The memo is:\n");
	for(i=1;i<=len1;i++){
		for(j=1;j<=len2;j++){
			printf("%c ",*(memo+len2*i+j));
		}
		printf("\n");
	}
}
/*
 * recursive method to find lcs
*/
static int sub_lcs(const char *s1, const char *s2, int i, int j, int len1, int len2, int *lcs_len, char *memo)
{
	int y,l,u;
	int max, tmpy, tmpl, tmpu;
	char c;
	
	if(s1[i-1] == s2[j-1]){
		if(*(lcs_len+(i-1)*len2+j-1) >= 0)
			y = *(lcs_len+(i-1)*len2+j-1);
		else
			*(lcs_len+(i-1)*len2+j-1) = y = sub_lcs(s1, s2, i-1, j-1, len1, len2, lcs_len, memo);
		tmpy = y+1;
	}else{
		if(*(lcs_len+(i)*len2+j-1) >= 0)
			l = *(lcs_len+(i)*len2+j-1);
		else
			*(lcs_len+(i)*len2+j-1) = l = sub_lcs(s1, s2, i, j-1, len1, len2, lcs_len, memo);
		tmpl = l;

		if( *(lcs_len+(i-1)*len2+j) >= 0)
			u = *(lcs_len+(i-1)*len2+j);
		else
			*(lcs_len+(i-1)*len2+j) = u = sub_lcs(s1, s2, i-1, j, len1, len2, lcs_len, memo);
		tmpu = u;
	}
	if(tmpy < tmpl){
		max = tmpl;
		*(memo+i*len2+j) = 'l';
	}else{
		max = tmpy;
		*(memo+i*len2+j) = 'y';
	}
	if(max < tmpu){
		max = tmpu;
		*(memo+i*len2+j) = 'u';
	}

	*(lcs_len+i*len2+j) = max;

	return max;
}

static int lcs_r(const char *s1, const char *s2, int len1, int len2, int *lcs_len, char *memo)
{
	int i,j;

	if(!s1 || !s2)
		return 0;
	if(!len1 || !len2)
		return 0;

	if(!lcs_len)
		return -1;

	for(i=0;i<=len1;i++)
		for(j=0;j<=len2;j++)
			*(lcs_len+len2*i+j) = -1;
	
	for(i=0;i<=len1;i++)
		*(lcs_len+len2*i) = 0;
	
	for(i=0;i<=len2;i++)
		*(lcs_len+i) = 0;

	for(i=0;i<=len1;i++)
		for(j=0;j<=len2;j++)
			*(memo+len2*i+j) = 'o';

	sub_lcs(s1, s2, len1, len2, len1, len2, lcs_len, memo);
	return 0;
}

int main()
{
	int err = 0;
	char s1[] = "ABCBDAB";
	char s2[] = "BDCABA";

	int len1 = strlen(s1);
	int len2 = strlen(s2);

	int *lcs_len = malloc(sizeof(int)*(len1+1)*(len2+1));
	char *memo = malloc(sizeof(char)*(len1+1)*(len2+1));
	
	err = lcs_r(s1, s2, len1, len2, lcs_len, memo);
	print_array_int(lcs_len, len1, len2);
	print_array_char(memo, len1, len2);
	print_lcs(s1, memo, len1, len2, len1, len2);
	free(lcs_len);
	free(memo);

	return err;
}

