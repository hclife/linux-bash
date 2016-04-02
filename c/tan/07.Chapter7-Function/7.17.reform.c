#include <stdio.h>
#include <string.h>

int digit(long long x)
{
	long long i;
	int dig;

	for (i = 10LL, dig = 1; ; i *= 10LL, dig++) {
		//printf("i = %lld\n", i);
		if (x / i == 0)
			break;
	}

	return dig;
}

void output(long long x, int d, long long v)
{
	long long r;

	if (d <= 0)
		return;

	//printf("x: %lld, d = %d, v = %lld\n", x, d, v);
	if (d == 1) {
		printf("%c\n", x + '0');
		return;
	}

	r = x / v;
	//printf("r = %lld\n", r);
	printf("%c", r + '0');
	return output(x - r * v, d - 1, v / 10LL);

}

int main(void)
{
	long long n, div;
	int i, d;

	scanf("%lld", &n);
	//printf("%lld\n", n);

	if (!n) {
		printf("0\n");
		return 0;
	}

	if (n < 0) {
		printf("-");
		n = -n;
	}
	d = digit(n);
	//printf("d = %d\n", d);

	div = 1;
	for (i = 1; i < d; i++)
		div *= 10LL;
	output(n, d, div);

	return 0;
}
