#include <stdio.h>

int main(void)
{
	int i;
	int sum;

	sum = 1;
	for (i = 10; i > 1; i--) {
		//printf("i = %d, sum = %d\n", i, sum);
		sum = (sum * 2) + 2;
	}
	printf("%d\n", sum);

	return 0;
}
