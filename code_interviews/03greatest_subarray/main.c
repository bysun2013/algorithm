#include <stdio.h>
#include <stdlib.h>

/**
    题目：输入一个整形数组，数组里有正数也有负数。
    数组中连续的一个或多个整数组成一个子数组，每个子数组都有一个和。
    求所有子数组的和的最大值。要求时间复杂度为O(n)。

    例如输入的数组为1, -2, 3, 10, -4, 7, 2, -5，和最大的子数组为3, 10, -4, 7, 2，
    因此输出为该子数组的和18。

    Done in 2014.4.3 by B.Y.sun
*/

#define MAXN 50
int greatest_subarray(int* array, int n, int *sum);

int main(int argc, char *argv[]) {

	int array[MAXN];
	int s, great_sum;
	unsigned int i=0;

	printf("Please input an array of int:\n");
	do{
		scanf("%d", &s);
		array[i++]=s;
	}while(getchar()!='\n');

	int result = greatest_subarray(array, i, &great_sum);
	if(result != 0)
		return result;
	printf("The greatest subarray is %d.\n", great_sum);
	return 0;
}

int greatest_subarray(int* array, int n, int *sum){
	int i, max_sum=0, cur_sum=0;

	if(!array || n==0)
		return 1;
	for(i=0;i<n;i++){
		cur_sum+=array[i];
		if(cur_sum < 0){
            cur_sum=0;
		}

		if(cur_sum > max_sum){
            max_sum= cur_sum;
		}
	}
	/*if all is negative, choose the biggest one */
	if(max_sum == 0){
		cur_sum=array[0];
		for(i=1;i<n;i++){
			if(array[i] > max_sum)
				max_sum= array[i];
		}
	}
	*sum = max_sum;
	return 0;
}
