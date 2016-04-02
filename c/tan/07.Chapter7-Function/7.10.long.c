#include <stdio.h>
#include <string.h>

#define MAXN	128
#define MAXL	128

int check_alpha(char c)
{
	if (c >= 'a' && c <= 'z')
		return 1;
	if (c >= 'A' && c <= 'Z')
		return 1;
	return 0;
}

void output_longest(char s[])
{
	char string[MAXN][MAXL];
	int n = strlen(s);
	int i, j, p, max, idx;

	//puts(s);
	memset(string, 0, sizeof(string));
	j = 0;
	p = 1;
	for (i = 0; i < n; i++) {
		if (!check_alpha(s[i])) {
			if (!j)
				continue;
			string[p++][j] = '\0';
			j = 0;
			continue;
		}
		string[p][j++] = s[i];
	}

	max = idx = 0;
	for (i = 1; i <= p; i++) {
		//printf("strlen = %d\n", strlen(string[i]));
		if (max < strlen(string[i])) {
			max = strlen(string[i]);
			idx = i;
		}
	}

	//printf("max = %d, idx = %d\n", max, idx);
	puts(string[idx]);


}

int main(void)
{
	char str[MAXL];

	memset(str, 0, sizeof(str));
	gets(str);
	output_longest(str);

	return 0;
}
