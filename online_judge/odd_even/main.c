/*
 * Topic 1169
 * 第一行输入一个数，为n，第二行输入n个数，
 * 这n个数中，如果偶数比奇数多，输出NO，否则输出YES
 * */
#include <stdio.h>
#include <stdlib.h>

static int total;

int main()
{
	int n;

	while(scanf("%d", &n) != EOF && n){
		int i, num;
		total = 0;
		for(i=0;i<n;i++){
			scanf("%d", &num);
			if(num % 2 == 0)
				total++;
			else
				total--;
		}

		if(total > 0)
			printf("NO\n");
		else
			printf("YES\n");
	}
	return 0;
}
