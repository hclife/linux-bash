#include <stdio.h>
#include <string.h>

int main(void)
{
	char str1[60] = "what is abc.";
	char str2[30] = "Now the second string.";
	int p, i;

	//printf("%s\n", str1);
	//printf("%s\n", str2);

	p = strlen(str1);
	for (i = 0; i < strlen(str2); i++)
		str1[p+i] = str2[i];

	printf("%s\n", str1);

	return 0;
}

