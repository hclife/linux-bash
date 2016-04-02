#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXM	64
#define MAXN	128

char str[MAXM][MAXN];
char in[MAXN];

int main(void)
{
	int i, j, r;
	char ch;
	FILE *fp;

	fp = fopen("char.txt", "w+");
	if (!fp) {
		printf("open fail\n");
		exit(1);
	}

	i = 0;
	memset(str, 0, sizeof(str));
	//while (scanf("%s", in) > 0)
		//strcpy(str[++i], in);

	while (fgets(in, sizeof(in), stdin))
		strcpy(str[++i], in);

#if 0
	printf("The string list:\n");
	for (j = 1; j <= i; j++)
		printf("%s", str[j]);
#endif

	for (j = 1; j <= i; j++)
		fprintf(fp, "%s", str[j]);

#if 0
	rewind(fp);
	while (!feof(fp)) {
		ch = fgetc(fp);
		if (ch == EOF)
			break;
		putchar(toupper(ch));
	}
#endif

	long len = ftell(fp);
	//printf("len = %ld\n", len);
	rewind(fp);
	while ((ch=fgetc(fp))!=EOF)
		putchar(toupper(ch));

	fclose(fp);
	return 0;
}
