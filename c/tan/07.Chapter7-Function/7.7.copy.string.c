#include <stdio.h>
#include <string.h>

#define MAX	128

void copy_pronouce_char(char *s1, char *s2, int n1)
{
	int i, j;

	for (i = j = 0; i < n1; i++) {
		switch (s1[i]) {
		case 'a':
		case 'A':
		case 'e':
		case 'E':
		case 'i':
		case 'I':
		case 'o':
		case 'O':
		case 'u':
		case 'U':
			s2[j++] = s1[i];
			break;
		default:
			break;
		}
	}
	s2[j++] = '\0';
}

int main(void)
{
	char str1[MAX], str2[MAX];

	memset(str1, 0, sizeof(str1));
	memset(str2, 0, sizeof(str2));
	scanf("%s", str1);

	copy_pronouce_char(str1, str2, strlen(str1));

	puts(str2);

	return 0;
}
