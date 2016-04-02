#include <stdio.h>
#include <math.h>

int main(void)
{
	double x, y, x1, y1, x2, y2, x3, y3, x4, y4;
	double d1, d2, d3, d4;
	double r = 1.0f;
	int tower = 10;
	int h;

	x1 = 2;  y1 = 2;
	x2 = -2; y2 = 2;
	x3 = -2; y3 = -2;
	x4 = 2;  y4 = -2;
	printf("Please input the position: ");
	scanf("%lf %lf", &x, &y);

	d1 = sqrt((x - x1) * (x - x1) + (y - y1) * (y - y1));
	d2 = sqrt((x - x2) * (x - x2) + (y - y2) * (y - y2));
	d3 = sqrt((x - x3) * (x - x3) + (y - y3) * (y - y3));
	d4 = sqrt((x - x4) * (x - x4) + (y - y4) * (y - y4));

	if (d1 <= 1.0f || d2 <= 1.0f || d3 <= 1.0f || d4 <= 1.0f)
		h = tower;
	else
		h = 0;

	printf("The height of building is %d\n", h);

	return 0;
}
