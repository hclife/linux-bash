#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int main(void)
{
	FILE *fp;
	char ch;

	fp = fopen("test.txt", "w");
	if (!fp) {
		printf("open fail\n");
		exit(1);
	}

	while ((ch = getchar()) != '!')
		fputc(toupper(ch), fp);
	fclose(fp);

	return 0;
}
