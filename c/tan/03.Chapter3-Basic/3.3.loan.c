#include <stdio.h>
#include <math.h>

int main(void)
{
	double A;
	double d = 300000.0f, p = 6000.0f, r = 0.01f;
	double m;

	//scanf("%lf", &A);
	//printf("log(%lf) = %lf\n", A, log10(A));

	m = log10(p / (p - d * r)) / log10(1 + r);
	printf("m = %6.3lf\n", m);

	return 0;
}
