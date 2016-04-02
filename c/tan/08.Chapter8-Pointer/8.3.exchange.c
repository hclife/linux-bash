#include <stdio.h>
#include <string.h>

void swap(int *a, int *b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

void input(int *p)
{
	int i;
	memset(p, 0, sizeof(p));
	for (i = 0; i < 10; i++)
		scanf("%d", p+i);
}

void process(int *p)
{
	int i, j, k, min, max;

	k = 0; min = *p;
	for (i = 1; i < 10; i++) {
		if (min > *(p+i)) {
			k = i;
			min = *(p+i);
		}
	}
	if (k) swap(p, p+k);

	k = 9; max = *(p+9);
	for (j = 8; j >= 0; j--) {
		if (max < *(p+j)) {
			k = j;
			max = *(p+j);
		}
	}
	if (k != 9) swap(p+9, p+k);
}

void output(int *p)
{
	int i;
	for (i = 0; i < 10; i++)
		printf("%d ", *(p+i));
	printf("\n");
}

int main(void)
{
	int a[16];

#if 0
	freopen("8.3.in", "r", stdin);
	freopen("8.3.out", "w", stdout);
#endif

	input(a);
	process(a);
	output(a);
	return 0;
}
