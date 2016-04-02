#include <stdio.h>

double power(double x, int n)
{
	if (!n)
		return 1.0f;
	if (n == 1)
		return x;
	return x * power(x, n-1);
}

int main(void)
{
	float r = 0.1f;
	float p = 1.0f + r;
	float Ans = power(p, 10);

	printf("%.2f%%\n", Ans * 100);
	return 0;
}

