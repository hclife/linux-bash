#include <stdio.h>
#include <string.h>
#define MAX 1024

int mystrcmp(char *p1, char *p2)
{
	int i;

	for (i = 0; p1[i] || p2[i]; i++)
		if (p1[i]-p2[i])
			return p1[i]-p2[i];
	return 0;
}

int main(void)
{
	int i, j, T;
	char str1[MAX], str2[MAX];

	freopen("8.17.in", "r", stdin);
	setbuf(stdout, NULL);
	scanf("%d", &T);
	while (T--) {
		memset(str1, 0, sizeof(str1));
		memset(str2, 0, sizeof(str2));
		scanf("%s %s", str1, str2);
		//printf("%s\t\t: %s\n", str1, str2);
		printf("%d\n", mystrcmp(str1, str2));
	}

	return 0;
}

