#include <stdio.h>
#include <string.h>

int main(void)
{
	int data[16][16];
	int N = 10;
	int i, j;

	memset(data, 0, sizeof(data));
	for (i = 1; i <= 10; i++) {
		data[i][1] = data[i][i] = 1;
		for (j = 2; j <= i-1; j++)
			data[i][j] = data[i-1][j] + data[i-1][j-1];
	}

	//printf("The yanghui triangle is below:\n");
	for (i = 1; i <= 10; i++) {
		for (j = 1; j <= i; j++)
			printf("%3d ", data[i][j]);
		printf("\n");
	}

	return 0;
}



