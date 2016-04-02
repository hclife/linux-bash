#include <stdio.h>
#include <string.h>

double P(int n, int x)
{
	double A;

	if (!n)
		return 1;

	if (n == 1)
		return x;

	A = (double)(2 * n - 1) * (double)x - P(n-1, x) - (double)(n-1) * P(n-2, x);

	return A / (double)n;
}

int main(void)
{
	int N, X;

	scanf("%d %d", &N, &X);
	if (N < 0) {
		printf("N should not be negative\n");
		return 0;
	}

	printf("%lf\n", P(N, X));

	return 0;
}

