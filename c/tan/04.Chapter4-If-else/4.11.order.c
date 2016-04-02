#include <stdio.h>

void swap(int *a, int *b)
{
	int t;

	t = *a;
	*a = *b;
	*b = t;
}

int main(void)
{
	int a, b, c, d;
	int i, j, k;

	printf("Please enter 4 numbers: ");
	scanf("%d %d %d %d", &a, &b, &c, &d);

	if (a > b) swap(&a, &b);
	if (b > c) swap(&b, &c);
	if (c > d) swap(&c, &d);
	if (a > b) swap(&a, &b);
	if (b > c) swap(&b, &c);
	if (a > b) swap(&a, &b);

	printf("%d %d %d %d\n", a, b, c, d);

	return 0;
}

