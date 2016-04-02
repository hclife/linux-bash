#include <stdio.h>

int main(void)
{
	int max(int, int);
	int min(int, int);
	int (*p)(int, int);
	int a, b, c, n;

	printf("Please enter a & b: ");
	scanf("%d %d", &a, &b);
	printf("Please choose mode (1 / 2): ");
	scanf("%d", &n);
	if (n == 1)
		p = max;
	else if (n == 2)
		p = min;
	else
		return -1;

	c = (*p)(a, b);
	printf("a = %d, b = %d, out = %d, p = 0x%08x\n", a, b, c, p);
	return 0;
}

int max(int x, int y)
{
	if (x > y)
		return x;
	return y;
}

int min(int x, int y)
{
	if (x < y)
		return x;
	return y;
}
