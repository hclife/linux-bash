#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX	10

struct student {
	int num;
	char name[20];
	float score[3];
	float avg;
} stud[MAX];

int main(void)
{
	int i, j, k, r;
	FILE *fin, *fout;
	struct student new;

	fin = fopen("stud_sort.txt", "rb");
	if (!fin) {
		printf("open read fail\n");
		exit(1);
	}

	fout = fopen("stud_sort_new.txt", "wb");
	if (!fout) {
		printf("open write fail\n");
		fclose(fin);
		exit(2);
	}

	freopen("10.7.in", "r", stdin);
	scanf("%d %s %f %f %f", &new.num, new.name, &new.score[0],
				&new.score[1], &new.score[2]);
	new.avg = (new.score[0] + new.score[1] + new.score[2]) / 3.0f; 
	//printf("new.avg = %5.2f\n", new.avg);

	for (i = 1; i <= 5; i++)
		fread(&stud[i], sizeof(struct student), 1, fin);
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

#if 0
	printf("\n");
	for (i = 1; i <= 6; i++)
		printf("%4d %-7s %5.2f %5.2f %5.2f %5.2f\n",
			stud[i].num, stud[i].name, stud[i].score[0],
			stud[i].score[1], stud[i].score[2], stud[i].avg);
#endif

	for (i = 1; i <= 6; i++) {
		r = fwrite(&stud[i], sizeof(struct student), 1, fout);
		if (r != 1) {
			printf("write fail\n");
			exit(5);
		}
	}

	fclose(fout);
	fclose(fin);

	return 0;
}

