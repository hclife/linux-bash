#include <stdio.h>

int main(void)
{
	int n;
	double h = 100.0f;
	int count = 10;
	double meter = 0.0f;;

	while (count--) {
		meter += 2.0f * h;
		//printf("meter = %lf\n", meter);
		h /= 2.0f;
		//printf("h = %lf\n\n", h);
	}
	meter -= 100.0f;
	printf("%lf\n", meter);
	printf("%lf\n", h);

	return 0;
}
