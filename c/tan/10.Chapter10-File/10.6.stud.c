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
       
	fin = fopen("stud.txt", "rb");
	if (!fin) {
		printf("open to read fail\n");
		exit(1);
	}

	fout = fopen("stud_sort.txt", "wb");
	if (!fout) {
		printf("open to write fail\n");
		fclose(fin);
		exit(2);
	}

	for (i = 1; i <= 5; i++)
		fread(&stud[i], sizeof(struct student), 1, fin);

#if 1
	for (i = 1; i <= 5; i++)
		printf("%4d %-7s %5.2f %5.2f %5.2f %5.2f\n",
			stud[i].num, stud[i].name, stud[i].score[0],
			stud[i].score[1], stud[i].score[2], stud[i].avg);
#endif

	for (i = 1; i <= 4; i++) {
		struct student tmp;

		k = i;
		for (j = i+1; j <= 5; j++)
			if (stud[k].avg < stud[j].avg)
				k = j;
		tmp = stud[i];
		stud[i] = stud[k];
		stud[k] = tmp;
	}

#if 1
	printf("\n");
	for (i = 1; i <= 5; i++)
		printf("%4d %-7s %5.2f %5.2f %5.2f %5.2f\n",
			stud[i].num, stud[i].name, stud[i].score[0],
			stud[i].score[1], stud[i].score[2], stud[i].avg);
#endif

	for (i = 1; i <= 5; i++) {
		r = fwrite(&stud[i], sizeof(struct student), 1, fout);
		if (r != 1) {
			printf("write fail\n");
			exit(3);
		}
	}

	fclose(fout);
	fclose(fin);

	return 0;
}
