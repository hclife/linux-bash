#include <stdio.h>
#include <math.h>

int main(void)
{
	double x, x1, x2;
	double a, b, c, d;
	double val;
	int i, n;

	a = 2.0f;
	b = -4.0f;
	c = 3.0f;
	d = -6.0f;
	x1 = -10.0f;
	x2 = 10.0f;

	n = 100000;
	for (i = 0; i < n; i++) {
		x = (x1 + x2) / 2.0f;
		val = ((a * x + b) * x + c) * x + d;
		if (val == 0)
			break;
		if (fabs(x - x1) < 1e-5)
			break;
		if (fabs(x - x2) < 1e-5)
			break;
		if (val < 0)
			x1 = x;
		else
			x2 = x;
	}
	printf("i = %d, x = %lf, x1 = %lf, x2 = %lf\n", i, x, x1, x2);

	return 0;
}

