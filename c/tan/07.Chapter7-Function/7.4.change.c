#include <stdio.h>
#include <string.h>

#define MAX	6

void change_matrix_form(int array[MAX][MAX], int n)
{
	int i, j;
	int temp;



	//printf("change_matrix_form enter\n");

#ifdef DBG
	printf("The array data before:\n");
	for (i = 1; i <= n; i++) {
		for (j = 1; j <= n; j++)
			printf("%d ", array[i][j]);
		printf("\n");
	}
#endif

	for (i = 1; i <= n; i++) {
		for (j = i; j <= n; j++) {
			if (i == j)
				continue;
			//printf("array[%d][%d] = %d\n", i, j, array[i][j]);
			//printf("array[%d][%d] = %d\n", j, i, array[j][i]);
			temp = array[i][j];
			array[i][j] = array[j][i];
			array[j][i] = temp;
			//printf("array[%d][%d] = %d\n", i, j, array[i][j]);
			//printf("array[%d][%d] = %d\n", j, i, array[j][i]);
			//printf("\n");
		}

	}

#ifdef DBG
	printf("The array data after:\n");
	for (i = 1; i <= n; i++) {
		for (j = 1; j <= n; j++)
			printf("%d ", array[i][j]);
		printf("\n");
	}
#endif

}

int main(void)
{
	int N;
	int data[MAX][MAX];
	int i, j;

	freopen("change.txt", "r", stdin);
	setbuf(stdout, NULL);
	memset(data, 0, sizeof(data));
	N = 3;
	for (i = 1; i <= N; i++)
		for (j = 1; j <= N; j++)
			scanf("%d", &data[i][j]);

#ifdef DBG_OUT
	printf("The original matrix data:\n");
	for (i = 1; i <= N; i++) {
		for (j = 1; j <= N; j++)
			printf("%d ", data[i][j]);
		printf("\n");
	}
#endif

	change_matrix_form(data, N);

#ifdef DBG_OUT
	printf("The changed matrix data:\n");
	for (i = 1; i <= N; i++) {
		for (j = 1; j <= N; j++)
			printf("%d ", data[i][j]);
		printf("\n");
	}
#endif

	return 0;
}
