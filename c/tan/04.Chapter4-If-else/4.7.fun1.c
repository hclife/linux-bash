#include <stdio.h>

int main(void)
{
	int x, y;

	printf("Please enter x: ");
	scanf("%d", &x);
	y = -1;
	if (x)
		if (x > 0)
			y = 1;
		else
			y = 0;
	printf("x = %d, y = %d\n", x, y);

	return 0;
}
