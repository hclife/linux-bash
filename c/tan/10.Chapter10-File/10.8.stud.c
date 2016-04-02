#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX	10

struct student {
	int num;
	char name[20];
	float score[3];
	float avg;
} stud[MAX], data[MAX];;

int main(void)
{
	int i, j, k, r;
	FILE *fp;
	struct student new;

	fp = fopen("stud_sort.txt", "rb+");
	if (!fp) {
		printf("open read fail\n");
		exit(1);
	}

	freopen("10.7.in", "r", stdin);
	scanf("%d %s %f %f %f", &new.num, new.name, &new.score[0],
				&new.score[1], &new.score[2]);
	new.avg = (new.score[0] + new.score[1] + new.score[2]) / 3.0f; 
	//printf("new.avg = %5.2f\n", new.avg);

	for (i = 1; i <= 5; i++)
		fread(&stud[i], sizeof(struct student), 1, fp);
#if 0
	for (i = 1; i <= 5; i++)
		printf("%4d %-7s %5.2f %5.2f %5.2f %5.2f\n",
			stud[i].num, stud[i].name, stud[i].score[0],
			stud[i].score[1], stud[i].score[2], stud[i].avg);
#endif

	for (i = 1; i <= 5; i++)
		if (new.avg <= stud[i].avg)
			break;
	for (j = 5; j >= i; j--)
		stud[j+1] = stud[j];
	stud[i] = new;

	rewind(fp);
	for (i = 1; i <= 6; i++) {
		r = fwrite(&stud[i], sizeof(struct student), 1, fp);
		if (r != 1) {
			printf("write failed: %d\n", r);
			fclose(fp);
			exit(5);
		}
	}

#if 0
	i = 0;
	memset(data, 0, sizeof(data));
	rewind(fp);
	while (!feof(fp)) {
		i++;
		r = fread(&stud[i], sizeof(struct student), 1, fp);
		if (r)
			printf("%4d %-7s %5.2f %5.2f %5.2f %5.2f\n",
				stud[i].num, stud[i].name, stud[i].score[0],
				stud[i].score[1], stud[i].score[2], stud[i].avg);
	}
#endif

	fclose(fp);

	return 0;
}

