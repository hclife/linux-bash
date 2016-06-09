#include <stdio.h>

int power(int m, int n);

main()
{
	int i;

	for (i = 0; i < 10; i++)
		printf("%d %4d\t%6d\n", i, power(2, i), power(-3, i));
}

int power(int base, int n)
{
	int i, p;

	for (i = p = 1; i <= n; i++)
		p *= base;
	return p;
}
