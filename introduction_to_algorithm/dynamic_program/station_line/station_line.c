#include <stdio.h>

#define s_len 6
#define l_num 2

static int l[l_num+1][s_len+1];
static int l_final, f_final;
static int f[l_num+1][s_len+1];

/* 
 * a[][] represent time neeeded to assemble, t[][] represent time of shift
 * e[] means start time, x[] means leave time
*/
static int fastest_way(int a[][s_len+1], int t[][s_len], int e[],int x[], int len)
{
	int tmp1, tmp2, i;
	
	f[1][1] = e[1] + a[1][1];
	f[2][1] = e[2] + a[2][1];

	for(i=2;i<7;i++){
		tmp1 = f[1][i-1] + a[1][i];
		tmp2 = f[2][i-1] + t[2][i-1] + a[1][i];
		if(tmp1 < tmp2){
			f[1][i] = tmp1;
			l[1][i] = 1;
		}else{
			f[1][i] = tmp2;
			l[1][i] = 2;
		}

		tmp1 = f[2][i-1] + a[2][i];
		tmp2 = f[1][i-1] + t[1][i-1] + a[2][i];
		if(tmp1 < tmp2){
			f[2][i] = tmp1;
			l[2][i] = 2;
		}else{
			f[2][i] = tmp2;
			l[2][i] = 1;
		}
	}

	tmp1 = f[1][len];
	tmp2 = f[2][len];
	if(tmp1 < tmp2){
		f_final = tmp1 + x[1];
		l_final = 1;
	}else{
		f_final = tmp2 + x[2];
		l_final = 2;
	}
	
	return 0;
}

static void show_way()
{
	int i = s_len;
	int line = l_final;
	printf("The fastest way is:\n");

	printf("line %d\tstation %d\n", line, i);
	line = l[line][i--];
	for(;i>0;i--){
		printf("line %d\tstation %d\n", line, i);
		line = l[line][i];
	}

}
static void print_station(int station, int line)
{
	if(station > 1){
		print_station(station - 1, l[line][station]);
	}
	printf("line %d\tstation %d\n", line, station);
}

static void show_station()
{
	printf("\nThe fastest way of stations:\n");
	print_station(s_len, l_final);
}
static void show_array(int a[][s_len+1], int m){
	int i,j;
	int n = s_len + 1;	
	
	printf("\n");
	for(i=0; i< m; i++){
		for(j=0;j< n;j++){
			printf("%3d ", a[i][j]);
		}
		printf("\n");
	}
}
int main()
{
	int a[l_num+1][s_len+1] = 
	{
		{0,},
		{0,7,9,3,4,8,4},
		{0,8,5,6,4,5,7}
	};

	int t[l_num+1][s_len] = 
	{
		{0,},
		{0,2,3,1,3,4},
		{0,2,1,2,2,1}
	};

	int e[] = {0,2,4};
	int x[] = {0,3,2};

	fastest_way(a, t, e, x, s_len);
	printf("The array of f is:\n");
	show_array(f, l_num+1);
	printf("The array of l is:\n");
	show_array(l, l_num+1);
	printf("\nThe l_final is: %d\n", l_final);
	printf("\nThe f_final is: %d\n", f_final);

	show_way();
	show_station();
	return 0;
}
