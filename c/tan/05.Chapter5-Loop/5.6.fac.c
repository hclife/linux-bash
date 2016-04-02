#include <stdio.h>
#include <string.h>

long long fac(int n)
{
	if (n <= 1)
		return 1;

	return n * fac(n-1);
}

int main(void)
{
	int N, n;
	long long sum = 0LL;
	double ans;

	N = 20;
	for (n = 1; n <= 20; n++)
		sum += fac(n);
	printf("%lld\n", sum);
	ans = (double)sum;
	printf("%22.15e\n", ans);

	return 0;
}


