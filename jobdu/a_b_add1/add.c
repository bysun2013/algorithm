#include <stdio.h>
#include <stdlib.h>

static int add(int a, int b, int k)
{
	int sum, result = -1;
	int i, a_tmp, b_tmp;
	sum = a + b;
	
	for(i=0;i<k;i++){
		a_tmp = a%10;
		b_tmp = b%10;

		if(a_tmp != b_tmp){
			result = sum;
			break;
		}

		a /= 10;
		b /= 10;
	}

	return result;
}

int main()
{
	int a, b, k;

	while(scanf("%d%d%d", &a, &b, &k) != EOF && (a || b)){
		int result;
		result = add(a, b, k);
		printf("%d\n", result);
	}

	return 0;
}
