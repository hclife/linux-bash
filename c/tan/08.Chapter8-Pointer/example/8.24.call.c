#include <stdio.h>

void fun(int x, int y, int (*p)(int, int));
int max(int, int);
int min(int, int);
int add(int, int);

int main(void)
{
	int a = 34, b = -21, n;
	printf("Please choose mode (1/2/3): ");
	scanf("%d", &n);
	switch (n) {
	case 1:
		fun(a, b, max);
		break;
	case 2:
		fun(a, b, min);
		break;
	case 3:
		fun(a, b, add);
		break;
	default:
		printf("mode %d not supported\n", n);
		return -1;
	}

	return 0;
}

void fun(int x, int y, int (*p)(int, int))
{
	int r = (*p)(x, y);
	printf("%d\n", r);
}

int max(int x, int y)
{
	printf("max = ");
	if (x > y)
		return x;
	return y;
}

int min(int x, int y)
{
	printf("min = ");
	if (x < y)
		return x;
	return y;
}

int add(int x, int y)
{
	printf("sum = ");
	return x + y;
}
