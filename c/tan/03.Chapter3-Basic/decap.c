#include <stdio.h>

int main(void)
{
	char c1, c2;

	c1 = getchar();
	c2 = c1 + 32;
	putchar(c2);
	putchar('\n');

	return 0;
}
