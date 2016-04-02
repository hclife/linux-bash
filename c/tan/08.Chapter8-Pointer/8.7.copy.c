#include <stdio.h>
#include <string.h>

#define MAX 1024
char buf[MAX], new[MAX];

char *new_string(const char *sin, char *sout, int m)
{
	int i, j;

	for (i = m-1, j = 0; *(sin+i); i++, j++)
		*(sout+j) = *(sin+i);
	*(sout+j) = '\0';

	return sout;
}

int main(void)
{
	int n, m;

	//freopen("8.7.in", "r", stdin);
	setbuf(stdout, NULL);
	scanf("%d", &m);
	memset(buf, 0, sizeof(buf));
	memset(new, 0, sizeof(new));
	scanf("%s", buf);
	n = strlen(buf);
	//printf("%2d: %s\n", n, buf);
	printf("%s\n", new_string(buf, new, m));

	return 0;
}
