#include <stdio.h>
#include <stdlib.h>

static int angle_per_hour = 30;

double clock(double h, double m)
{
	double h_angle, m_angle, angle;
	
	if(h >= 12)
		h = h - 12;

	h_angle = h*angle_per_hour + m*30/60;
	m_angle = m/5*30;

	angle = h_angle - m_angle;
	if(angle < 0)
		angle = -1 * angle; 

	if(angle >=180)
		angle = 360 - angle;

	return angle;
}

int main()
{
	int h, m;

	while(scanf("%d:%d", &h, &m) != EOF){
		double angle;
		angle = clock(h, m);
		printf("%.2f\n", angle);
	}

	return 0;
}

