#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	FILE *fp1, *fp2;

	fp1 = fopen("file1.dat", "r");
	if (!fp1) {
		printf("open file1 fail\n");
		exit(1);
	}

	fp2 = fopen("file2.dat", "w");
	if (!fp2) {
		printf("open file2 fail\n");
		fclose(fp1);
		exit(2);
	}

	while (!feof(fp1)) putchar(getc(fp1));
	putchar(10);
	rewind(fp1);
	while (!feof(fp1)) putc(getc(fp1), fp2);

	fclose(fp2);
	fclose(fp1);

	return 0;
}
