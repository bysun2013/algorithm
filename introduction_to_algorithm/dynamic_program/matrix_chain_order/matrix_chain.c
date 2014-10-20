#include <stdio.h>
#include <limits.h>

#define LEN 6
static int m[LEN+1][LEN+1], splite[LEN+1][LEN+1];

static void show_array(int a[LEN+1][LEN+1])
{
	int i,j;
	int m, n;
	m =n = LEN + 1;	
	
	printf("\n");
	for(i=0; i< m; i++){
		for(j=0;j< n;j++){
			printf("%7d ", a[i][j]);
		}
		printf("\n");
	}
}

static void print_chain_order(int start, int end)
{
	if(start == end)
		printf("A%d", start);
	else{
		printf("(");
		print_chain_order(start, splite[start][end]);
		print_chain_order(splite[start][end] + 1, end);
		printf(")");
	}

}
static int matrix_chain_order(int p[], int n)
{
	int l,i,j,k;

	for(i=1;i<=n;i++)
		m[i][i] = 0;

	for(l=2;l<=n;l++){
		for(i=1;i<=n-l+1;i++){
			j = i+l-1;
			int tmp, m_min = INT_MAX;
			for(k=i;k<j;k++){
				tmp = m[i][k] + m[k+1][j] + p[i-1]*p[k]*p[j];
				if(tmp < m_min){
					m_min = tmp;
					splite[i][j] = k;
				}
			}
			m[i][j] = m_min;
		}	
	}
}

int main()
{
	int p[] = {30,35,15,5,10,20,25};

	matrix_chain_order(p, LEN);
	printf("\nThe matrix cost table is: \n");
	show_array(m);
	printf("\nThe matrix splite table is: \n");
	show_array(splite);
	printf("\nThe matrix chain order is:\n");
	print_chain_order(1, LEN);
	printf("\n\n");
}
