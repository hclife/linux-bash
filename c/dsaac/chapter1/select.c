/* select problem */
#include <stdio.h>
#include <string.h>

int N, K;
int Ans;
int data[1000];

void swap(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

void Bubble_down(int a[], int n)
{
	int i, j;

	for (i = 1; i < n; i++)
		for (j = 1; j <= n-i; j++)
			if (a[j] < a[j+1])
				swap(&a[j], &a[j+1]);
}


int main(void)
{
	int T;
	int i, j;

	freopen("select.txt", "r", stdin);
	setbuf(stdout, NULL);
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &N);
		K = N / 2;

		memset(data, 0, sizeof(data));
		for (i = 1; i <= N; i++)
			scanf("%d", &data[i]);

#if 1
		printf("N = %d, K = %d\n", N, K);
		for (i = 1; i <= N; i++)
			printf("%d ", data[i]);
		printf("\n");
#endif

		Bubble_down(data, N);

#if 1
		printf("After bubble down sort:\n");
		for (i = 1; i <= N; i++)
			printf("%d ", data[i]);
		printf("\n");
#endif

		Ans = data[K];
		printf("%d\n", Ans);

	}

	return 0;
}



