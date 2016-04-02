#include <stdio.h>
#include <string.h>

int main(void)
{
	char s1[64], s2[64];
	int i;

	memset(s1, 0, sizeof(s1));
	memset(s2, 0, sizeof(s2));
	scanf("%s", s2);
	for (i = 0; i <= strlen(s2); i++)
		s1[i] = s2[i];

	printf("%s\n", s1);

	return 0;
}



