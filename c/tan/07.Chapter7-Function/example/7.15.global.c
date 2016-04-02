#include <stdio.h>

int a = 3, b = 5;

int main(void)
{
	int max(int a, int b);
	int a = 8;

	printf("max = %d\n", max(a, b));

	return 0;
}

int max(int a, int b)
{
	return a > b ? a : b;
}
