#include <stdio.h>
#include <string.h>

#define MAX	10000007

int main(void)
{
	int a[16], b[16], mark[16];
	int N = 10;
	int i, j, idx;
	int min;

	memset(a, 0, sizeof(a));
	memset(b, 0, sizeof(b));
	memset(mark, 0, sizeof(mark));

	for (i = 1; i <= N; i++)
		scanf("%d", &a[i]);
	for (i = 1; i <= N; i++)
		mark[i] = 1;

	for (i = 1; i <= N; i++)
		printf("%d ", a[i]);
	printf("\n");

	/* algorithm */
	for (i = 1; i <= N; i++) {
		min = MAX;
		idx = 0;
		for (j = 1; j <= N; j++) {
			if (!mark[j])
				continue;
			if (min > a[j]) {
				min = a[j];
				idx = j;
			}
		}
		b[i] = min;
		mark[idx] = 0;
	}

	for (i = 1; i <= N; i++)
		printf("%d ", b[i]);
	printf("\n");


	return 0;
}

