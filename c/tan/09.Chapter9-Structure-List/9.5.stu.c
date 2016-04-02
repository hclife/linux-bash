#include <stdio.h>
#include <string.h>

struct student {
	int num;
	char name[32];
	double score[4];
} s[16];

double avg_score[4] = {0.0f};

void input(struct student p[])
{
	int i;

	for (i = 1; i <= 10; i++)
		scanf("%d %s %lf %lf %lf", &p[i].num, &p[i].name,
		      &p[i].score[1], &p[i].score[2], &p[i].score[3]);
}

void average(struct student p[])
{
	int i, j;
	double s, t;

	t = 0.0f;
	for (i = 1; i <= 3; i++) {
		s = 0.0f;
		for (j = 1; j <= 10; j++)
			s += p[j].score[i];
		s /= 10.0f;
		t += s;
		avg_score[i] = s;
	}

	t /= 3.0f;
	printf("Total average score is %5.2lf\n", t);
}

void high(struct student p[])
{
	int i, j;
	int maxi;
	double max, sum, avg;

	maxi = 1;
	max = -1;
	avg = 0;
	for (i = 1; i <= 10; i++) {
		sum = 0;
		for (j = 1; j <= 3; j++)
			sum += p[i].score[j];

		if (max < sum) {
			max = sum;
			maxi = i;
			avg = sum / 3.0f;
		}
	}

	printf("No.%d is the highest:\n%-5d %-7s %5.1lf %5.1lf %5.1lf average: %5.1lf\n",
			maxi, p[maxi].num, p[maxi].name, p[maxi].score[1],
			p[maxi].score[2], p[maxi].score[3], avg);
}

int main(void)
{
	freopen("9.5.in", "r", stdin);
	setbuf(stdout, NULL);
	memset(s, 0, sizeof(s));
	input(s);
	average(s);
	high(s);
	return 0;
}
