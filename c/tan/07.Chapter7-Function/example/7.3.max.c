#include <stdio.h>

int main(void)
{
	int max(float x, float y);

	float a, b, d;
	int c;

	scanf("%f %f", &a, &b);
	c = max(a, b);
	d = max(a, b);
	printf("max = %d = %f\n", c, d);

	return 0;
}

int max(float x, float y)
{
	float z;

	z = x > y ? x : y;

	return z;
}
