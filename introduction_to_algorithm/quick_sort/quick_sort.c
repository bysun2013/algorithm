/*
 * quick_sort.c
 *
 *  Created on: Feb 25, 2014
 *      Author: bing
 */

static int adjust(int a[],int start, int end)
{
	int x=a[start];
	int i=start, j=end;
	while(i < j)
	{
		while(a[j]>x && i<j)
			j--;
		if(i<j){
			a[i]=a[j];
			i++;
		}
		while(a[i]<x && i<j)
			i++;
		if(i<j){
			a[j]=a[i];
			j--;
		}
	}
	a[i]=x;
	return i;
}

void quick_sort(int a[],int start, int end){
	int partition;
	if(start< end)
	{
		partition= adjust(a, start, end);
		quick_sort(a, start, partition-1);
		quick_sort(a, partition+1, end);

	}
}
