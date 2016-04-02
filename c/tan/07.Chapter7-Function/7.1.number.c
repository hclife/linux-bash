#include <stdio.h>

int divisor(int a, int b)
{
	if (a % b == 0)
		return b;

	return divisor(b, a % b);
}

int multipler(int a, int b)
{
	int d = divisor(a, b);

	return a * b / d;
}

int main(void)
{
	int A, B;
	int D, M;

	scanf("%d %d", &A, &B);

	D = divisor(A, B);
	M = multipler(A, B);

	printf("%d %d\n", D, M);

	return 0;
}
