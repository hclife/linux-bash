#include <stdio.h>

int main(void)
{
	int a, b, c;
	int count;
	double n;
	double sum = 0.0f;

	a = 2;
	b = 1;
	count = 20;
	while (count--) {
		n = (double)a / (double)b;
		//printf("a = %d, b = %d, n = %10.5lf\n", a, b, n);
		//printf("n = %d / %d = %10.5lf\n", a, b, n);
		sum += n;
		c = b;
		b = a;
		a += c;
	}
	printf("%lf\n", sum);

	return 0;
}
