#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX	128

struct employee {
	char name[20];
	int num;
	char sex[6];
	int age;
	char addr[64];
	int pay;
	char health[10];
	char degree[10];
};

struct employee data[MAX];
int N;

int main(void)
{
	int i, j, r;
	FILE *fin, *fout;

	fin = fopen("employee.txt", "r");
	if (!fin) {
		printf("open read fail\n");
		exit(1);
	}

	fout = fopen("salary.txt", "w");
	if (!fout) {
		printf("open write fail\n");
		fclose(fin);
		exit(2);
	}

	i = 0;
	memset(data, 0, sizeof(data));
	while (1) {
		i++;
		r = fscanf(fin, "%s %d %s %d %s %d %s %s", data[i].name, &data[i].num,
			data[i].sex, &data[i].age, data[i].addr, &data[i].pay,
			data[i].health, data[i].degree);
		//printf("fscanf return %d\n", r);
		if (!data[i].num)
			break;
	}
	i--;

#if 0
	for (j = 1; j <= i; j++) {
		printf("%s:%d:%s:%d:%s:%d:%s:%s\n", data[j].name, data[j].num,
			data[j].sex, data[j].age, data[j].addr, data[j].pay,
			data[j].health, data[j].degree);
	}
#endif

	for (j = 1; j <= i; j++) {
		r = fprintf(fout, "%s %d\n", data[j].name, data[j].pay);
		//printf("fprintf return %d\n", r);
	}

	fclose(fout);
	fclose(fin);

	return 0;
}
