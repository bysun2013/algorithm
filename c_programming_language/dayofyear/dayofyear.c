#include <stdio.h>


static char daytab[2][13]={
		{0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
		{0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
};

/* day_of_year: set day of year from month & day
 * if true,return 0; else return 1;
 * */
int dayofyear(int year,int month,int day){
	int i,leap;
	leap=(year%4==0&&year%100!=0)||year%400==0;
	if(month>12||month<0||day<0||day>daytab[leap][month])
		return 0;
	for(i=1;i<month;i++)
		day+=daytab[leap][i];
	return day;

}

/* month_day: set month, day from day of year
 * if true, return 0;else return 0;
 * */
int month_day(int year,int dayofyear,int* month,int* day){
	int i,leap;
	leap=(year%4==0&&year%100!=0)||year%400==0;
	if(leap&&dayofyear>366||!leap&&dayofyear>365)
		return 1;
	for(i=1;dayofyear>daytab[leap][i];i++)
		dayofyear-=daytab[leap][i];
	*month=i;
	*day=dayofyear;
	return 0;
}


int main(){
	int month,day,year,daysofyear;
	printf("Please input year,month and day:");
	scanf("%d%d%d",&year,&month,&day);
	daysofyear=dayofyear(year,month,day);
	if(!daysofyear)
		return 1;
	printf("%d %d,%d is %d\n",month,day,year,daysofyear);

	printf("\n-------------------------------------------------\n");

	printf("Please input year,dayofyear:");
	scanf("%d%d",&year,&daysofyear);
	month_day(year,daysofyear,&month,&day);
	printf("The date of %d in %d is %d %d \n",daysofyear,year,month,day);

	return 0;
}
