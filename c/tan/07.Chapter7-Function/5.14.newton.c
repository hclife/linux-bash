#include <stdio.h>
#include <math.h>

int main(void)
{
	double x0, x;
	double fx, f1x;
	double a, b, c, d;

	a = 2.0f;
	b = -4.0f;
	c = 3.0f;
	d = -6.0f;
	x = 1.5f;
	do {
		x0 = x;
		fx = ((a * x0 + b) * x0 + c) * x0 + d;
		f1x = (3.0f * a * x0 + 2.0f * b) * x0 + d;
		x = x0 - fx / f1x;
		//printf("x = %lf, x0 = %lf\n", x, x0);
	} while (fabs(x - x0) >= 1e-2);
	printf("x = %lf, x0 = %lf\n", x, x0);

	return 0;
}
