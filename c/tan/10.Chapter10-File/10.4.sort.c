#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX	1024

char str[MAX];

int main(void)
{
	FILE *fp1, *fp2, *fp3;
	char ch, tmp;
	int i, j, k;

	fp1 = fopen("A", "r");
	if (!fp1) {
		printf("open A fail\n");
		exit(1);
	}

	fp2 = fopen("B", "r");
	if (!fp2) {
		printf("open B fail\n");
		fclose(fp1);
		exit(2);
	}

	fp3 = fopen("C", "w");
	if (!fp3) {
		printf("open C fail\n");
		fclose(fp2);
		fclose(fp1);
		exit(3);
	}

	i = 0;
	memset(str, 0, sizeof(str));
	while (!feof(fp1)) {
		ch = fgetc(fp1);
		if ((ch >= 'a' && ch <= 'z') ||
		    (ch >= 'A' && ch <= 'Z'))
			str[i++] = ch;
	}

	while (!feof(fp2)) {
		ch = fgetc(fp2);
		if ((ch >= 'a' && ch <= 'z') ||
		    (ch >= 'A' && ch <= 'Z'))
			str[i++] = ch;
	}

	for (i = 0; i < strlen(str)-1; i++) {
	       k = i;
	       for (j = i+1; j < strlen(str); j++)
		       if (str[k] > str[j])
			       k = j;
	       tmp = str[i];
	       str[i] = str[k];
	       str[k] = tmp;
	}

	//printf("%s", str);

	for (i = 0; i < strlen(str); i++)
		fputc(str[i], fp3);

	fclose(fp3);
	fclose(fp2);
	fclose(fp1);

	return 0;
}
