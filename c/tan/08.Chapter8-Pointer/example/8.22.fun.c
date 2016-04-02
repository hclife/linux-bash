#include <stdio.h>
#include <string.h>

int max(int, int);
int (*p)(int, int);

int main(void)
{
	int a, b, c;

	p = max;
	printf("Please enter a / b: ");
	scanf("%d %d", &a, &b);
	c = (*p)(a, b);
	printf("a = %d\nb = %d\nmax = %d\n", a, b, c);

	return 0;
}

int max(int x, int y)
{
	int z;

	if (x > y)
		z = x;
	else
		z = y;

	return z;
}

