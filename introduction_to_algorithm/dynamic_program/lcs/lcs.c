#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*
 * find the longest common subsequence
*/
static int lcs(const char *s1, const char *s2, int len1, int len2, int *lcs_len, char *memo)
{
	int i, j;
	
	if(!s1 || !s2)
		return 0;
	if(!len1 || !len2)
		return 0;

	if(!(lcs_len && memo))
		return -1;

	for(i=0;i<=len1;i++){
		*(lcs_len+len2*i) = 0;
	}
	for(i=0;i<=len2;i++){
		*(lcs_len+i) = 0;
	}

	for(i=1;i<=len1;i++){
		for(j=1;j<=len2;j++){
			if(s1[i-1] == s2[j-1]){
				*(lcs_len+i*len2+j) = *(lcs_len+(i-1)*len2+j-1) + 1;
				*(memo+i*len2+j) = 'y';
			}else{
				int max =*(lcs_len+len2*(i-1)+j);
				*(memo+i*len2+j) = 'u';
				
				if(max <= *(lcs_len+len2*i+j-1)){
					max = *(lcs_len+i*len2+j-1);
					*(memo+i*len2+j) = 'l';
				}
			}
		}
	}
}

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
			printf("%d ",*(lcs_len+len2*i+j));
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

int main()
{
	char s1[] = "ABCBDAB";
	char s2[] = "BDCABA";

	int len1 = strlen(s1);
	int len2 = strlen(s2);

	int *lcs_len = malloc(sizeof(int)*(len1+1)*(len2+1));
	char *memo = malloc(sizeof(char)*(len1+1)*(len2+1));

	int err = lcs(s1,s2,len1,len2,lcs_len,memo);

	print_array_int(lcs_len, len1, len2);
	print_array_char(memo, len1, len2);

	printf("The longest common subsequence is:\n");
	print_lcs(s1, memo, len1, len2, len1, len2);
	printf("\n");

	free(lcs_len);
	free(memo);

	return err;
}

