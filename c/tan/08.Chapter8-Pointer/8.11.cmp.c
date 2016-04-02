#include <stdio.h>
#include <string.h>

void sort(char *p[], int l, int r)
{
	int i = l, j = r;
	char *k = p[l];

	if (l >= r)
		return;
	while (i < j) {
		while (i < j && strcmp(p[j], k) >= 0) j--;
		p[i] = p[j];
		while (i < j && strcmp(p[i], k) <= 0) i++;
		p[j] = p[i];
	}
	p[i] = k;
	sort(p, l, i-1);
	sort(p, i+1, r);
}

int N;
int main(void)
{
	char *p[16] = {0};
	char str[16][128] = {0};
	int i, j;

	freopen("8.11.in", "r", stdin);
	setbuf(stdout, NULL);
	N = 10;
	for (i = 1; i <= N; i++)
		scanf("%s", str[i]);

	for (i = 1; i <= N; i++)
		p[i] = str[i];

	sort(p, 1, 10);

	for (i = 1; i <= N; i++)
		printf("%s\n", p[i]);

	return 0;
}
