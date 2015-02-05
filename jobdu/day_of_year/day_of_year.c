#include <stdio.h>
#include <stdlib.h>

#define MONTH_YEAR 12


static int unleap[MONTH_YEAR+1];

static int is_leap(int year)
{
	int leap;
	
	if(year%4 == 0 && year%100 != 0 || year%400 == 0)
		return 1;

	return 0;
}

static int days_of_month(int unleap[], int n)
{
	int unleap_month[] = {0,31,28,31,30,31,30,31,31,30,31,30,31};
	int i;
	
	unleap[1] = 0;
	for(i=2;i<=n;i++){
		unleap[i] = unleap[i-1]+unleap_month[i-1];
	}

	return 0;
}

static int day_of_year(int year, int month, int day)
{
	int isleap, total;
	isleap = is_leap(year);

	total = unleap[month]+day;
	if(isleap){
		if(month>2)
			return (total + 1);
		else
			return total;
	}else{
		return total;
	}
}

int main()
{
	int year, month, day;

	days_of_month(unleap, MONTH_YEAR);
	while(scanf("%d%d%d", &year, &month, &day) !=EOF){
		printf("%d\n",day_of_year(year, month, day));
	}

	return 0;
}
