#include <stdio.h>
#include <string.h>

int main(void)
{
	int T;
	int i, j;
	int space;

	space = 0;
	for (i = 1; i <= 5; i++) {
		for (j = 1; j <= space; j++)
			printf(" ");
		for (j = 1; j <= 5; j++)
			printf("* ");
		printf("\n");

		space += 2;
	}

	return 0;
}
