#include <stdio.h>
#include <string.h>

int main(void)
{
	int x, i, j;
	int N = 10;
#if 0
	int data[64] = {0, 1, 4, 8, 9, 14,
			20, 25, 28, 31, 33, 0};
#else
	int data[64] = {0, 1, 4, 6, 9, 13, 16,
			19, 28, 40, 100};
#endif

	scanf("%d", &x);

	printf("Before: ");
	for (i = 1; i <= N; i++)
		printf("%2d ", data[i]);
	printf("\n");

	/* algorithm */
	for (i = 1; i <= N; i++)
		if (x <= data[i])
			break;
	//printf("i = %d\n", i);

	for (j = N; j >= i; j--) {
		data[j+1] = data[j];
	}
	data[i] = x;

	printf("After:  ");
	for (i = 1; i <= N+1; i++)
		printf("%2d ", data[i]);
	printf("\n");

	return 0;
}

