#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX	128

struct employee {
	char name[20];
	int pay;
} data[MAX];

int N = 5;

int main(void)
{
	int i, j, x, r;
	FILE *fp;

	fp = fopen("salary.txt", "r");
	if (!fp) {
		printf("open read fail\n");
		exit(1);
	}

	for (i = 1; ; i++)
		if (2 != fscanf(fp, "%s %d", data[i].name, &data[i].pay))
			break;
	N = i-1;
	if (N <= 0) {
		printf("file empty\n");
		fclose(fp);
		return 0;
	}

	while (1) {
		scanf("%d", &x);
		if (x >= 1 && x <= N)
			break;
		printf("Please enter between 1~%d\n", N);
	}
	data[x].pay = 0;
	fclose(fp);

	fp = fopen("salary.txt", "w");
	if (!fp) {
		printf("open write fail\n");
		exit(2);
	}

	for (i = 1; i <= N; i++) {
		if (!data[i].pay)
			continue;
		fprintf(fp, "%s %d\n", data[i].name, data[i].pay);
	}

	fclose(fp);
	return 0;
}
