#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
/*
��Ŀ������
��һ����ά�����У�ÿһ�ж����մ����ҵ�����˳������ÿһ�ж����մ��ϵ��µ�����˳������
�����һ������������������һ����ά�����һ���������ж��������Ƿ��и�������
���룺
������ܰ��������������������ÿ�����԰�����
����ĵ�һ��Ϊ��������m��n(1<=m,n<=1000)������Ҫ����ľ����������������
����ĵڶ��а���һ������t(1<=t<=1000000)������Ҫ���ҵ����֡�
��������m�У�ÿ����n������������Ŀ��������m��n�еľ���(��������Ŀ������ʾ��ÿһ�ж����մ����ҵ�����˳������ÿһ�ж����մ��ϵ��µ�����˳������)
�����
��Ӧÿ�����԰�����
�����Yes�������ڶ�ά�������ҵ�������t��
�����No�������ڶ�ά������û���ҵ�����t��
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
/*������ʼ���row��column�ع��� ��ָ������ ��*/
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
	/*��ʱarr[i][i]����t, �Ӵ�λ�����Ϻ�������ұȽ�*/ 
	/*���ϲ���*/ 
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
