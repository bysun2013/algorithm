#include <stdio.h>
#include <stdlib.h>
#include <string.h>


static void insert_bstree(int t[], int key){
	int i = 1;
	while(t[i] != -1){
		if(key > t[i])
			i = 2*i + 1;
		else
			i= 2*i;
	}

	t[i] = key;
}

/* n is the length of array t, the length of s is returned */
static int build_bstree(const char *s, int t[], int n){
	int i;
	int tmp;

	for(i=0;i<n;i++)
		t[i] = -1;
	i=1;
	while(*s != '\0'){
		tmp = (*s - '0');
		if(i == 1)
			t[1] = tmp;
		else
			insert_bstree(t, tmp);
		s++;
		i++;
	}
	return i-1;
}

static int is_same_bstree(const int a[], const int b[], int n){
	int i=0;
	
	for(;i<n;i++){
		if(a[i] != b[i])
			return 0;
	}

	return 1;
}

#define BSTREE_LEN 1024
int main(){
	char s[20];
	int ss[BSTREE_LEN];
	int n, i, s_size;

	while(scanf("%d", &n) != EOF && n){
		int tt[BSTREE_LEN];
		char t[20];
		int t_size;

		scanf("%s", s);
		s_size = build_bstree(s, ss, BSTREE_LEN);
		
		for(i=0;i<n;i++){
			scanf("%s", t);
			t_size = build_bstree(t, tt, BSTREE_LEN);
			if(t_size != s_size){
				printf("NO\n");
			}else{
				if(is_same_bstree(ss, tt, BSTREE_LEN))
					printf("YES\n");
				else
					printf("NO\n");
			}
		}
	}
	return 0;
}
