#include <stdio.h>
#include <string.h>
#define MAX	128

void move(int *p, int n, int m)
{
	int i;
	int tmp[MAX];

	memset(tmp, 0, sizeof(tmp));
#if 0
	printf("move\n");
	for (i = 1; i < 4; i++)
		printf("%d ", *(p+i));
	printf("\n");
#endif

	for (i = 1; i <= m; i++)
		tmp[i] = *(p+n-m+i);

#if 0
	printf("tmp:\n");
	for (i = 1; i <= m; i++)
		printf("%d ", tmp[i]);
	printf("\n");
#endif

	for (i = n-m; i >= 1; i--)
		*(p+m+i) = *(p+i);

	for (i = 1; i <= m; i++)
		*(p+i) = tmp[i];
}

int main(void)
{
	int a[MAX];
	int i, j, k, m, n;

	//freopen("8.4.in", "r", stdin);
	//freopen("8.4.out", "w", stdout);
	setbuf(stdout, NULL);
	memset(a, 0, sizeof(a));
	scanf("%d %d", &n, &m);
	for (i = 1; i <= n; i++)
		scanf("%d", &a[i]);

	//printf("main: n=%d, m=%d\n", n, m);
	printf("From: ");
	for (i = 1; i <= n; i++)
		printf("%2d ", a[i]);
	printf("\n");
	move(a, n, m);
	printf("To:   ");
	for (i = 1; i <= n; i++)
		printf("%2d ", a[i]);
	printf("\n");


	return 0;
}
