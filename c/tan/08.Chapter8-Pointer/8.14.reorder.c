#include <stdio.h>
#include <string.h>

#define MAX 1024
int num[MAX];

void reorder(int *p, int n)
{
	int tmp[MAX];
	int i;

	memset(tmp, 0, sizeof(tmp));
	for (i = n; i >= 1; i--)
		tmp[n+1-i] = *(p+i);
	for (i = 1; i <= n; i++)
		*(p+i) = tmp[i];
}

int main(void)
{
	int i, n = 10;

	freopen("8.14.in", "r", stdin);
	setbuf(stdout, NULL);
	memset(num, 0, sizeof(num));
	for (i = 1; i <= n; i++)
		scanf("%d", &num[i]);
	reorder(num, n);
	for (i = 1; i <= n; i++)
		printf("%d ", num[i]);
	printf("\n");

	return 0;
}
