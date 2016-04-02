#include <stdio.h>
#include <string.h>

#define MAX	128

void revert_string_order(char s[], int n)
{
	int i;
	char c;

	for (i = 0; i < n/2; i++) {
		c = s[i];
		s[i] = s[n-i-1];
		s[n-i-1] = c;
	}
}

int main(void)
{
	char str[MAX];

	memset(str, 0, sizeof(str));
	scanf("%s", str);
	revert_string_order(str, strlen(str));
	puts(str);

	return 0;
}
