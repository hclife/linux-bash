#include <stdio.h>

int divisor(int a, int b)
{
	if (a % b)
		return divisor(b, a % b);

	return b;
}

int main(void)
{
	int a, b, c, d;

	printf("Please input two numbers ");
	scanf("%d %d", &a, &b);
	c = divisor(a, b);
	printf("The max divisor is %d\n", c);

	a /= c;
	b /= c;
	d = a * b * c;
	printf("The min multiple is %d\n", d);

	return 0;
}





