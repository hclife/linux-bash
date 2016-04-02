#include <stdio.h>
#include <string.h>
#include <math.h>

/* ax^3 + bx^2 + cx + d = 0 */
double newton_solution(double a, double b, double c,
		       double d, double key)
{
	double x0, fx, f1x;
	double x = key;

	//printf("a = %lf, b = %lf, c = %lf, d = %lf, key = %lf\n", a, b, c, d, key);
	do {
		x0 = x;
		fx = ((a * x0 + b) * x0 + c) * x0 + d;
		f1x = (3.0f * a * x0 + 2.0f * b) * x0 + c;
		x = x0 - fx / f1x;
		//printf("x = %lf, x0 = %lf\n", x, x0);
	} while (fabs(x - x0) >= 1e-2);

	return x0;
}

int main(void)
{
	double A, B, C, D, K, R;

	scanf("%lf %lf %lf %lf %lf", &A, &B, &C, &D, &K);

	R = newton_solution(A, B, C, D, K);
	printf("%lf\n", R);

	return 0;
}




