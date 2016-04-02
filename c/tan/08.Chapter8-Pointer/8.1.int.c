#include <stdio.h>

void swap(int *a, int *b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

void sort(int *a, int *b, int *c)
{
	if (*a > *b) swap(a, b);
	if (*a > *c) swap(a, c);
	if (*b > *c) swap(b, c);
}

int main(void)
{
	int a, b, c;

	scanf("%d %d %d", &a, &b, &c);
	sort(&a, &b, &c);
	printf("%d %d %d\n", a, b, c);

	return 0;
}
