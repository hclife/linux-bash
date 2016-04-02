#include <stdio.h>

void sort(int *m[], int n);
int main(void)
{
	int a[5] = {1, 30, 15, 7, 19};
	int *num[5] = {&a[0], &a[1], &a[2], &a[3], &a[4]};
	int **p, i;

	sort(num, 5);
	p = num;
	for (i = 0; i < 5; i++)
		printf("%d ", **p++);
	printf("\n");

	return 0;
}

void sort(int *m[], int n)
{
	int i, j, k;
	int *tmp;

	for (i = 0; i < n-1; i++) {
		k = i;
		for (j = i+1; j < n; j++)
			if (*m[k] > *m[j])
				k = j;

		//printf("i = %d, k = %d\n", i, k);
		if (k != i) {
			tmp = m[i];
			m[i] = m[k];
			m[k] = tmp;
		}
	}
}
