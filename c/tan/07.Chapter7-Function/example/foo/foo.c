#include <stdio.h>
#include <string.h>

int main(void)
{
	char str[80], ch;
	int i, j;
	
	gets(str);

	printf("Please input the deleted character: ");
	ch = getchar();

	for (i = j = 0; str[i] != '\0'; i++)
		if (str[i] != ch)
			str[j++] = str[i];
	str[j] = '\0';

	puts(str);

	return 0;
}
