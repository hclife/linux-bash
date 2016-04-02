#include <stdio.h>
#include <string.h>

#define MAX	1024
int a[MAX];
int n, p, last;

void visit(int x, int c)
{
	//printf("visit: %d, %d\n", x, c);
	if (p >= n)
		return;

	if (x > n) {
		visit(x-n, c);
		return;
	}

	if (a[x] < 0) {
		visit(x+1, c);
		return;
	}

	if (c == 3) {
		a[x] = -1;
		last = x;
		p++;
		visit(x+1, 1);
		return;
	}

	visit(x+1, c+1);
}

int main(void)
{
	int i, j;

	scanf("%d", &n);
	memset(a, 0, sizeof(a));
	for (i = 1; i <= n; i++)
		a[i] = i;

	last = 1;
	p = 0;
	visit(1, 1);
	printf("%d\n", last);

	return 0;
}
