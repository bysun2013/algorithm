/*
 * 给定两个整数A和B，其表示形式是：从个位开始，每三位数用逗号","隔开。
 * 现在请计算A+B的结果，并以正常形式输出。
 * */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static int convert(char *a)
{
	int na = 0, i = 0;
	int len, flag = 1;

	len = strlen(a);

	if(a[0] == '-'){
		flag = -1;
		i++;
	}else if(a[0] == '+'){
		i++;
	}

	for(;i<len;i++){
		if(a[i] != ',' && (a[i] > '9' || a[i] < '0'))
			break;
		if(a[i] == ',')
			continue;
		na = na*10 +(a[i] - '0');
	}
	return na * flag;
}


int main()
{
	char a[20], b[20];

	while(scanf("%s%s", a, b) != EOF){
		printf("%d\n", convert(a) + convert(b));
	}

	return 0;
}
