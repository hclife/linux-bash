#include <stdio.h>
#include <math.h>

double a, b, c, delta;
double r, r1, r2;

void output_root_pos(void)
{
	double x = sqrt(delta);

	r1 = ((-1.0f) * b + x) / (2.0f * a);
	r2 = ((-1.0f) * b - x) / (2.0f * a);

	printf("x1 = %lf, x2 = %lf\n", r1, r2);
}

void output_root_neg(void)
{
	double x = sqrt(-delta);
	
	//printf("x1 = (-%lf + %lfi) / %lf\n", b, x, 2.0f * a);
	//printf("x2 = (-%lf - %lfi) / %lf\n", b, x, 2.0f * a);

	printf("x1 = %lf + %lfi\n", (-b) / (2.0f * a), x / (2.0f * a));
	printf("x1 = %lf - %lfi\n", (-b) / (2.0f * a), x / (2.0f * a));
}

void output_root_zero(void)
{
	r = (-b) / (2.0f * a);

	printf("x = %lf\n", r);
}

int main(void)
{

	printf("Please input a b c: ");
	scanf("%lf %lf %lf", &a, &b, &c);
	if (!a) {
		if (!b) {
			if (!c) {
				printf("any\n");
				return 0;
			}

			printf("none\n");
			return 0;
		}
		r = (-1.0f) * c / b;
		printf("root: %lf\n", r);
		return 0;
	}

	delta = b * b - 4.0f * a * c;
	if (delta > 0) {
		output_root_pos();
		return 0;
	}

	if (delta < 0) {
		output_root_neg();
		return 0;
	}

	output_root_zero();

	return 0;
}
