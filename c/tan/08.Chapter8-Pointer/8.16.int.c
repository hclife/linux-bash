#include <stdio.h>
#include <string.h>

#define MAX 1024
#define ULL unsigned long long
char str[MAX];
ULL data[MAX];
int d;

void transform(char *p)
{
	int i, j, s, e;
	ULL num, base, r;

	i = j = s = e = 0;
	for (i = 0; p[i]; i++) {
		if (p[i] < '0' || p[i] > '9')
			continue;

		s = i;
		for (j = s; p[j]; j++)
			if (p[j] < '0' || p[j] > '9')
				break;
		i = j;
		e = j-1;
		num = 0ULL;
		base = 1ULL;
		for (j = e; j >= s; j--) {
			num += (ULL)(p[j]-'0')*base;
			base *= 10ULL;
		}
		data[++d] = num;
	}
}

int main(void)
{
	int T, i, j;
	char ch;

	freopen("8.16.in", "r", stdin);
	setbuf(stdout, NULL);
	scanf("%d", &T);
	ch = getchar();
	while (T--) {
		memset(str, 0, sizeof(str));
		memset(data, 0ULL, sizeof(data));
		fgets(str, sizeof(str), stdin);
		//printf("%s", str);
		d = 0;
		transform(str);
		printf("%d: ", d);
		for (i = 1; i <= d; i++)
			printf("%llu ", data[i]);
		printf("\n");
	}

	return 0;
}
