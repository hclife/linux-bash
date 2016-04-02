#include <stdio.h>
#include <string.h>

#define MAX	128

void concatenate_string(char *s1, char *s2, int n1, int n2)
{
	int i, n;

	for (i = 0; i <= n2; i++)
		s1[n1+i] = s2[i];
}

int main(void)
{
	char str1[MAX], str2[MAX];

	memset(str1, 0, sizeof(str1));
	memset(str2, 0, sizeof(str2));
	scanf("%s", str1);
	scanf("%s", str2);
	concatenate_string(str1, str2, strlen(str1), strlen(str2));
	puts(str1);

	return 0;
}
