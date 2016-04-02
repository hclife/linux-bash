#include <stdio.h>
#include <math.h>

int main(void)
{
	double m;

	scanf("%lf", &m);
	while (m >= 1000) {
		printf("Please re-input the number:\n");
		scanf("%lf", &m);
	}

	printf("%d\n", (int)sqrt(m));

	return 0;
}
