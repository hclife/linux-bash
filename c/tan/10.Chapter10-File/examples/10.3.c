#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX	100

char str[MAX][10];

int main(void)
{
	FILE *fp;
	char tmp[10];
	int i, j, k, n = 3;

	for (i = 0; i < n; i++)
		fgets(str[i], 10, stdin);

	for (i = 0; i < n-1; i++) {
		k = i;
		for (j = i+1; j < n; j++)
			if (strcmp(str[k], str[j]) > 0)
				k = j;
		strcpy(tmp, str[i]);
		strcpy(str[i], str[k]);
		strcpy(str[k], tmp);
	}

	fp = fopen("/home/larkin/string.dat", "w");
	if (!fp) {
		printf("cannot open file\n");
		exit(1);
	}

	printf("The new sequence is:\n");
	for (i = 0; i < n; i++) {
		fputs(str[i], fp);
		//fputs("\n", fp);
		printf("%s", str[i]);
	}

	return 0;
}
