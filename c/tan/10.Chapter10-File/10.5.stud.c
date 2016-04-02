#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX	10

struct student {
	int num;
	char name[20];
	float score[3];
	float avg;
} data[MAX];

int main(void)
{
	int i, r;
	FILE *fp;
	
	freopen("10.5.in", "r", stdin);
	memset(data, 0, sizeof(data));
	fp = fopen("stud.txt", "wb");
	if (!fp) {
		printf("open fail\n");
		exit(1);
	}

	for (i = 1; i <= 5; i++) {
		scanf("%d %s %f %f %f", &data[i].num, data[i].name, &data[i].score[0],
					&data[i].score[1], &data[i].score[2]);
		data[i].avg = (data[i].score[0] + data[i].score[1] + data[i].score[2]) / 3.0f;
		r = fwrite(&data[i], sizeof(struct student), 1, fp);
		if (r != 1) {
			printf("write fail\n");
			fclose(fp);
			exit(2);
		}
	}
	fclose(fp);

	fp = fopen("stud.txt", "rb");
	if (!fp) {
		printf("open read fail\n");
		exit(3);
	}

	for (i = 1; i <= 5; i++) {
		fread(&data[i], sizeof(struct student), 1, fp);
		printf("%-10s %3d %7.2f %7.2f %7.2f %7.2f\n", data[i].name,
			data[i].num, data[i].score[0], data[i].score[1],
			data[i].score[2], data[i].avg);
	}
	fclose(fp);

	return 0;
}
