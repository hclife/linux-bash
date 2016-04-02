#include <stdio.h>
#include <string.h>

#define SIZE	10

struct student {
	char name[10];
	int num;
	int age;
	char addr[15];
} stud[SIZE];

void save(void)
{
	FILE *fp;
	int i, r;

	fp = fopen("stu.dat", "wb");
	if (!fp) {
		printf("open fail\n");
		return;
	}

	for (i = 0; i < SIZE; i++) {
		r = fwrite(&stud[i], sizeof(struct student), 1, fp);
		if (r != 1) {
			printf("write fail\n");
			break;
		}
	}

	fclose(fp);
}

int main(void)
{
	int i;

	freopen("10.4.in", "r", stdin);
	for (i = 0; i < SIZE; i++)
		scanf("%s %d %d %s", stud[i].name, &stud[i].num,
				  &stud[i].age, stud[i].addr);
	save();
	return 0;
}

