/* ax^2 + bx + c = 0 */
#include <stdio.h>
#include <math.h>

int main(void)
{
	double a, b, c, disc, x1, x2, p, q;
	scanf("%lf %lf %lf", &a, &b, &c);
	disc = b * b - 4 * a * c;
	p = -b / (2.0f * a);
	q = sqrt(disc) / (2.0f *a);
	x1 = p + q;
	x2 = p - q;
	printf("x1 = %7.2f\n", x1);
	printf("x2 = %7.2f\n", x2);

	printf("x1 = %f\n", x1);
	printf("x1 = %lf\n", x1);
	printf("x1 = %7.0f\n", x1);

	return 0;
}


