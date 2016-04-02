#include <stdio.h>
#define LETTER	0

int main(void)
{
	char str[20] = "C Language";
	char c;
	int i = 0;

	while (str[i]) {
#if LETTER
		str[i] = toupper(str[i]);
#else
		str[i] = tolower(str[i]);
#endif
		printf("%c", str[i]);
		i++;
	}
	printf("\n");

	return 0;
}
