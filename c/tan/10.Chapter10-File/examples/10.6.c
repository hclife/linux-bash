#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE	10

struct student {
	char name[10];
	int num;
	int age;
	char addr[15];
} stud[SIZE];

int main(void)
{
	FILE *fp;
	int i;

	fp = fopen("stu.dat", "rb");
	if (!fp) {
		printf("open fail\n");
		exit(1);
	}

	memset(stud, 0, sizeof(stud));
	for (i = 0; i < 10; i += 2) {
		fseek(fp, i*sizeof(struct student), 0);
		fread(&stud[i], sizeof(struct student), 1, fp);
		printf("%-10s %4d %4d %-15s\n", stud[i].name, stud[i].num,
			stud[i].age, stud[i].addr);
	}

	fclose(fp);
	return 0;
}

