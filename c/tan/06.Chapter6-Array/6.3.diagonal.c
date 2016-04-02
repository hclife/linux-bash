#include <stdio.h>
#include <string.h>

int main(void)
{
	int i, j;
	int data[4][4];
	int sum;

	memset(data, 0, sizeof(data));
	for (i = 1; i <= 3; i++)
		for (j = 1; j <= 3; j++)
			scanf("%d", &data[i][j]);

#if 0
	printf("The matrix data is:\n");
	for (i = 1; i <= 3; i++) {
		for (j = 1; j <= 3; j++)
			printf("%d ", data[i][j]);
		printf("\n");
	}
#endif

	sum = 0;
	for (i = 1; i <= 3; i++) {
#if 0
		if (i == 2) {
			sum += data[i][i];
			continue;
		}
		sum += data[i][1];
		sum += data[i][3];
#else
		sum += data[i][i];
#endif
	}
	printf("%d\n", sum);

	return 0;
}
