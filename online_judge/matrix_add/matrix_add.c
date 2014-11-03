/*
in this time, you are supposed to find A+B where A and B are two matrices,
and then count the number of zero rows and columns.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ZERO 1
#define NOZERO 2

int total_zero_colume_row(int *matrix, int m ,int n)
{
    int i, j;
    int *zero_colume = calloc(n, sizeof(int));
    int zero_row = ZERO, total_zero_row = 0, total_zero_colume = 0;

	for(i=0;i<n;i++)
		*(zero_colume+i) = ZERO;
    for(i=0;i<m;i++){
        for(j=0;j<n;j++){
            if(*(matrix+n*i+j)){
                zero_colume[j] = NOZERO;
                zero_row = NOZERO;
            }
        }
        if(zero_row == ZERO)
            total_zero_row++;

		zero_row = ZERO;
    }

    for(i=0;i<n;i++){
        if(zero_colume[i] == ZERO)
            total_zero_colume++;
    }
	free(zero_colume);
    return (total_zero_colume + total_zero_row);
}

static void print_array(int* array, int m, int n)
{
    int i,j;

    for(i=0;i<m;i++){
        for(j=0;j<n;j++){
            printf("%d ", *(array+n*i+j));
        }
        printf("\n");
    }
    printf("\n");
}
int main()
{
    int i,j,k,m,n;
    int tmp, *matrix;
    int zero_colume_row = 0;

    while(scanf("%d", &m) && m){
        scanf("%d", &n);
        matrix = (int *)calloc(m*n, sizeof(int));
        for(k = 0; k < 2; k++)
            for(i = 0;i < m; i++)
                for(j = 0; j < n; j++){
                    scanf("%d", &tmp);
                    *(matrix+n*i+j) += tmp;
                }
//      print_array(matrix, m, n);
        zero_colume_row = total_zero_colume_row(matrix, m, n);
        printf("%d\n", zero_colume_row);
        free(matrix);
    }

    return 0;
}

