#include <stdio.h>
#include <math.h>

double f1(double x)
{
	return sin(x);
}

double f2(double x)
{
	return cos(x);
}

double f3(double x)
{
	return exp(x);
}

double f4(double x)
{
	return x + 1.0f;
}

double f5(double x)
{
	return 2.0f*x+3.0f;
}

double f6(double x)
{
	return exp(x)+1.0f;
}

double f7(double x)
{
	return (1.0f+x)*(1.0f+x);
}

double f8(double x)
{
	return x*x*x;
}

double integral(double a, double b, double (*func)(double))
{
	double sum = 0.0f;
	double h = fabs(a-b)/100;
	double fx, x = a;
	int i;

	for (i = 0; i < 100; i++) {
		fx = (*func)(x+i*h+h/2.0f);
		sum += fx;
	}
	return sum*h;
}

int main(void)
{
	//double a = 0.0f, b = 1.0f, y = 0.0f;
	double a, b;
	scanf("%lf %lf", &a, &b);
	printf("sinx = %5.3lf\n", integral(a, b, f1));
	printf("cosx = %5.3lf\n", integral(a, b, f2));
	printf("expx = %5.3lf\n", integral(a, b, f3));
	printf("1+xx = %5.3lf\n", integral(a, b, f4));
	printf("2x+3 = %5.3lf\n", integral(a, b, f5));
	printf("ex+1 = %5.3lf\n", integral(a, b, f6));
	printf("1+x2 = %5.3lf\n", integral(a, b, f7));
	printf("xxx3 = %5.3lf\n", integral(a, b, f8));
	return 0;
}
