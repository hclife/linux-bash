#include <stdio.h>

struct student {
	int num;
	char name[20];
	float score;
};

int main(void)
{
	struct student stu[5] = {{10101, "Zhang", 78},
				 {10103, "Wang", 98.5},
				 {10106, "Li", 86},
				 {10108, "Ling", 73.5},
				 {10110, "Sun", 100}};
	struct student tmp;
	const int n = 5;
	int i, j, k;

	for (i = 0; i < n-1; i++) {
		k = i;
		for (j = i+1; j < n; j++)
			if (stu[k].score < stu[j].score)
				k = j;
		tmp = stu[k]; stu[k] = stu[i]; stu[i] = tmp;
	}
	for (i = 0; i < n; i++)
		printf("%6d %8s %6.2f\n", stu[i].num, stu[i].name, stu[i].score);

	return 0;
}
