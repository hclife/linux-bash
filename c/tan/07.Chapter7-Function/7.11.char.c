#include <stdio.h>
#include <string.h>

void swap(char *a, char *b)
{
	char t;

	t = *a;
	*a = *b;
	*b = t;
}

void bubble_order(char s[], int n)
{
	int i, j;

	//printf("%d: %s\n", n, s);

	for (i = 0; i < n-1; i++)
		for (j = 0; j <= n-i-2; j++)
			if (s[j] > s[j+1])
				swap(&s[j], &s[j+1]);
}

int main(void)
{
	int i, j;
	char str[128];

	memset(str, 0, sizeof(str));
	scanf("%s", str);
	bubble_order(str, strlen(str));
	puts(str);

	return 0;
}

