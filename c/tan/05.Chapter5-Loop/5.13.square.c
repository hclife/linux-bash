#include <stdio.h>
#include <math.h>

int main(void)
{
	int a;
	double x1, x2;

	printf("Please input a number: ");
	scanf("%d", &a);
	x1 = (double)a / 2.0f;
	x2 = (x1 * x1 + (double)a) / (2.0f * x1);
	while (fabs(x1 - x2) > (double)1e-5) {
		x1 = x2;
		x2 = (x1 * x1 + (double)a) / (2.0f * x1);
	}

	//printf("x1 = %lf, x2 = %lf\n", x1, x2);
	printf("%lf\n", x2);

	return 0;
}

