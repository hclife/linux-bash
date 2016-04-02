#include <stdio.h>

int main(void)
{
	char a[] = "House";
	char *b = "House";

	printf("main enter\n");
	a[2] = 'r';
	//*(b+2) = 'r';

	printf("%s\n", a);
	printf("%s\n", b);

	return 0;
}

