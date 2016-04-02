#include <stdio.h>

int main(void)
{
	int x, y;

	printf("Please input x: ");
	scanf("%d", &x);	
	if (x < 1)
		y = x;
	else if (x >= 1 && x < 10)
		y = 2 * x - 1;
	else
		y = 3 * x - 11;
	printf("%d\n", y);

	return 0;
}

