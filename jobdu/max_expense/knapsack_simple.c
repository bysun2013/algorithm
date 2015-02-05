/*
 *  现有一笔经费可以报销一定额度的发票。
 *  允许报销的发票类型包括买图书（A类）、文具（B类）、差旅（C类），
 *  要求每张发票的总额不得超过1000元，每张发票上，单项物品的价值不得超过600元。
 *  现请你编写程序，在给出的一堆发票中找出可以报销的、不超过给定额度的最大报销额。
 * */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* it exceed the maximum of memory provided, use enhanced version */
int q[31][3100001];  

static int max_num(int a, int b)
{
	if(a>=b)
		return a;
	return b;
}

static int max_expense(int a[], int n, int limit)
{
	int i, j;
	int t = limit > a[n] ? a[n]:limit;

	memset(q, 0, sizeof(q));
	for(i=0;i<t;i++)
		q[n][i] = 0;

	for(i=a[n];i<=limit;i++)
		q[n][i] = a[n];
	
	for(i=n-1;i>0;i--){
		t = limit > a[i] ? a[i]:limit;
		for(j=0;j<t;j++)
			q[i][j] = q[i+1][j];
		for(j=a[i];j<=limit;j++){
			q[i][j] = max_num(q[i+1][j], q[i+1][j-a[i]]+a[i]);
		}
	}

	return q[1][limit];
}

int main()
{
	char s[1000];
	int receipts[31];	
	double expense;
	int n;

	while(scanf("%lf%d", &expense, &n) != EOF && n){
		int i, nr = 0;

		getchar();
		for(i=0;i<n;i++){
			char *p;
			char type;
			double price;
			double total = 0;
			int j, m, flag = 1;

			fgets(s, sizeof(s), stdin);
			p = strtok(s, " ");
			m = atoi(p);

			for(j=0;j<m && p;j++){
				p = strtok(NULL, " ");
				sscanf(p, "%c:%lf", &type, &price);
				if(price > 600){
					flag = 0;
					break;
				}

				if(type != 'A' && type != 'B' && type != 'C'){
					flag = 0;
					break;
				}

				total += price;
				if(total > 1000 || total > expense){
					flag = 0;
					break;
				}
			}

			if(flag != 0)
				receipts[++nr] = total * 100;
		}
		printf("%.2lf\n", max_expense(receipts, nr, expense*100)/100.00);

	}

	return 0;
}
