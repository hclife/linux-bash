#include <stdio.h>

int main(void)
{
	char c1, c2;
	int i1, i2;

	printf("Please enter two integer numbers: ");
	scanf("%d %d", &i1, &i2);
	c1 = i1;
	c2 = i2;

	printf("char: %c, %c\n", c1, c2);
	printf("int : %d, %d\n", c1, c2);

	return 0;
}
