#include <stdio.h>
#include <string.h>

void sort(char **p, int l, int r)
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

int main(void)
{
	char *in[8] = {0};
	char str[8][128] = {0};
	int i, j, N;

	freopen("8.20.in", "r", stdin);
	setbuf(stdout, NULL);
	N = 5;
	for (i = 1; i <= N; i++) {
		scanf("%s", str[i]);
		in[i] = str[i];
	}

	sort(in, 1, N);
	for (i = 1; i <= N; i++)
		printf("%s\n", in[i]);

	return 0;
}
