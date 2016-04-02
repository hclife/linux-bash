#include <stdio.h>
#include <stdlib.h>
#define MAX 5

void swap(int *a, int *b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

void process_max(int a[MAX+1][MAX+1], int f[MAX+1][MAX+1])
{
	int i, j;
	int max, maxi, maxj;

	max = a[3][3];
	maxi = maxj = 3;

	for (i = 1; i <= MAX; i++) {
		for (j = 1; j <= MAX; j++) {
			if (max < a[i][j]) {
				max = a[i][j];
				maxi = i;
				maxj = j;
			}
		}
	}

	if (maxi != 3 || maxj != 3) {
		swap(&a[maxi][maxj], &a[3][3]);
		f[3][3] = 1;
	}
}

void process_min(int a[MAX+1][MAX+1], int f[MAX+1][MAX+1], int x, int y)
{
	int i, j;
	int mini = x;
	int minj = y;
	int min = a[x][y];

	for (i = 1; i <= MAX; i++) {
		for (j = 1; j <= MAX; j++) {
			if (f[i][j])
				continue;
			if (min > a[i][j]) {
				min = a[i][j];
				mini = i;
				minj = j;
			}
		}
	}
	//printf("min: a(%d, %d) = %d\n", mini, minj, min);
	if (mini != x || minj != y) {
		swap(&a[mini][minj], &a[x][y]);
		f[x][y] = 1;
	}
}

void process(int a[MAX+1][MAX+1], int f[MAX+1][MAX+1])
{
	int i, j;

	process_max(a, f);
	process_min(a, f, 1, 1);
	process_min(a, f, 1, MAX);
	process_min(a, f, MAX, 1);
	process_min(a, f, MAX, MAX);
}

void output(int a[MAX+1][MAX+1], int b[MAX+1][MAX+1])
{
	int i, j;

	for (i = 1; i <= MAX; i++) {
		for (j = 1; j <= MAX; j++)
			printf("%2d ", a[i][j]);
		printf("\n");
	}

#if 0
	for (i = 1; i <= MAX; i++) {
		for (j = 1; j <= MAX; j++)
			printf("%2d ", b[i][j]);
		printf("\n");
	}
#endif
}

int main(void)
{
	int i, j;
	int matrix[MAX+1][MAX+1] = {0};
	int visit[MAX+1][MAX+1] = {0};

	srand(2);
	for (i = 1; i <= MAX; i++)
		for (j = 1; j <= MAX; j++)
			matrix[i][j] = 1+rand()%100;
	//output(matrix, visit);
	process(matrix, visit);
	output(matrix, visit);
	return 0;
}
