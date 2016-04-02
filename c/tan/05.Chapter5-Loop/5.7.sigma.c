#include <stdio.h>

int main(void)
{
	int k;
	double sum = 0.0f;

	for (k = 1; k <= 100; k++)
		sum += k;

	for (k = 1; k <= 50; k++)
		sum += k * k;

	for (k = 1; k <= 10; k++)
		sum += (double)1.0f / (double)k;

	printf("%20.10lf\n", sum);
	
	return 0;
}
