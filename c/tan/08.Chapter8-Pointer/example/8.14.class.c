#include <stdio.h>

int main(void)
{
	void average(float *p, int n);
	void search(float (*p)[4], int n);
	void find(float (*p)[4], int n);

	float score[3][4] = {{65, 57, 70, 60}, {80, 87, 50, 81}, {90, 99, 100, 98}};

	average(*score, 12);
	search(score, 2);
	find(score, 3);

	return 0;
}

void average(float *p, int n)
{
	float *e;
	float sum, avg;

	sum = 0;
	e = p + n - 1;
	for (; p <= e; p++)
		sum += *p;
	avg = sum / n;
	printf("average = %5.2f\n", avg);
}

void search(float (*p)[4], int n)
{
	int i;

	printf("The score of No.%d are:\n", n);
	for (i = 0; i < 4; i++)
		printf("%5.2f ", *(*(p + n) + i));
	printf("\n");
}

void find(float (*p)[4], int n)
{
	int i, j, flag;

	for (j = 0; j < n; j++) {
		flag = 0;
		for (i = 0; i < 4; i++) {
			if (*(*(p+j)+i) < 60) {
				flag = 1;
				break;
			}
		}
		if (!flag)
			continue;

		printf("No.%d fails, the score is:\n", j+1);
		for (i = 0; i < 4; i++)
			printf("%5.1f", *(*(p+j)+i));
		printf("\n");
	}
}
