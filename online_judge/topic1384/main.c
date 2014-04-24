#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
/*
题目描述：
在一个二维数组中，每一行都按照从左到右递增的顺序排序，每一列都按照从上到下递增的顺序排序。
请完成一个函数，输入这样的一个二维数组和一个整数，判断数组中是否含有该整数。
输入：
输入可能包含多个测试样例，对于每个测试案例，
输入的第一行为两个整数m和n(1<=m,n<=1000)：代表将要输入的矩阵的行数和列数。
输入的第二行包括一个整数t(1<=t<=1000000)：代表要查找的数字。
接下来的m行，每行有n个数，代表题目所给出的m行n列的矩阵(矩阵如题目描述所示，每一行都按照从左到右递增的顺序排序，每一列都按照从上到下递增的顺序排序。)
输出：
对应每个测试案例，
输出”Yes”代表在二维数组中找到了数字t。
输出”No”代表在二维数组中没有找到数字t。
*/
static int m,n,t;
int main(int argc, char *argv[]) {
	int *arr;
	int i,j;
	int result= 0;
	printf("Please enter:\n");
	scanf("%d%d", &m, &n);
	scanf("%d",&t);
	arr=(int *)malloc(sizeof(int)*m*n);
	for(i=0;i<m;i++)
		for(j=0;j<n;j++){
			scanf("%d",&arr[i*m+j]);
		}
			

	printf("\n");
		
	result=test(pt,m,n,t);
	
	if(!result)
		printf("No\n");
	else
		printf("Yes\n");
		
	return 0;
}
/*根据起始点和row、column重构造 “指针数组 ”*/
int construct_array(int arry[], int x, int y, int row, int column){
	
	int** pt= (int **)malloc(sizeof(int *)*row);
	for(i=0;i<row;i++){
		pt[i]= &arr[x*n+y+i*n];
		//printf("%d\t",*pt[i]);
	}
}

int test(int *arr[], int m, int n, int t){
 	int i,j;
	int h=m>n?m:n;
	for(i=0;i<h;i++){
		if(arr[i][i]==t)
			return 1;
	
		if(arr[i][i]<t)
			continue;
	/*此时arr[i][i]大于t, 从此位置向上和向左查找比较*/ 
	/*向上查找*/ 
	for(j=i-1;j>=0;j--){
		if(arr[i][i]==t)
			return 1;
		if(arr[i][i]<t)
			break;
	}
	for(j=i-1;j>=0;j--){
		if(arr[i][i]==t)
			return 1;
		if(arr[i][i]<t)
			break;
	}
		
		
	}
}
