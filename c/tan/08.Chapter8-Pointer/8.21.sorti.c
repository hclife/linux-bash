#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 1024

void sort(int **p, int l, int r)
{
	int i = l, j = r;
	int *k = p[l];

	if (l >= r)
		return;
	while (i < j) {
		while (i < j && **(p+j) >= *k) j--;
		p[i] = p[j];
		while (i < j && **(p+i) <= *k) i++;
		p[j] = p[i];
	}
	p[i] = k;
	sort(p, l, i-1);
	sort(p, i+1, r);
}

int main(void)
{
	int n, i, j;
	int a[MAX] = {0};
	int *p[MAX] = {0};

	freopen("8.21.in", "r", stdin);
	setbuf(stdout, NULL);
	scanf("%d", &n);
	srand(1);
	for (i = 1; i <= n; i++) {
		//a[i] = 1+rand()%100;
		scanf("%d", &a[i]);
		p[i] = &a[i];
	}

	sort(p, 1, n);

#if 0
	for (i = 1; i <= n; i++)
		printf("%d ", a[i]);
	printf("\n");
#endif

	for (i = 1; i <= n; i++)
		printf("%d ", **(p+i));
	printf("\n");

	return 0;
}
