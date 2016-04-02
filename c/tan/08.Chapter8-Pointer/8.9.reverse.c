#include <stdio.h>

void reverse(int in[4][4], int out[4][4])
{
	int i, j;

	for (i = 1; i <= 3; i++)
		for (j = 1; j <= 3; j++)
			out[j][i] = in[i][j];
}

int main(void)
{
	int i, j;
	int output[4][4] = {0};
	int matrix[4][4] = {{0, 0, 0, 0},
			    {0, 1, 2, 3},
			    {0, 4, 5, 6},
			    {0, 7, 8, 9}};

	reverse(matrix, output);

#if 0
	for (i = 1; i <= 3; i++) {
		for (j = 1; j <= 3; j++)
			printf("%d ", matrix[i][j]);
		printf("\n");
	}
#endif

	for (i = 1; i <= 3; i++) {
		for (j = 1; j <= 3; j++)
			printf("%d ", output[i][j]);
		printf("\n");
	}
	return 0;
}
