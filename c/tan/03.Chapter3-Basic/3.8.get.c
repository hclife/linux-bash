#include <stdio.h>

int main(void)
{
	int c1, c2;

	c1 = getchar();
	c2 = getchar();

	printf("The two characters are: ");
	putchar(c1);
	putchar(c2);
	printf("\n");

	printf("%d, %d\n", c1, c2);

	return 0;
}
