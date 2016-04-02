#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int score[8][8];

double average_class(int p[8][8], int x)
{
	int i, ret;

	ret = 0;
	for (i = 1; i <= 4; i++)
		ret += p[i][x];
	return (double)ret / 4.0f;
}

double average_score(int p[8][8], int x)
{
	int j, ret;

	ret = 0;
	for (j = 1; j <= 5; j++)
		ret += p[x][j];
	return (double)ret / 5.0f;
}

void fail(int p[8][8])
{
	int i, j, f;

	for (i = 1; i <= 4; i++) {
		f = 0;
		for (j = 1; j <= 5; j++)
			if (p[i][j] < 60) f++;
		if (f < 2)
			continue;

		printf("Fail No.%d: ", i);
		for (j = 1; j <= 5; j++)
			printf("%d ", p[i][j]);
		printf(": %5.2lf\n", average_score(p, i));
	}
}

void good(int p[8][8])
{
	int i, j, f;

	for (i = 1; i <= 4; i++) {
		if (average_score(p, i) >= 90) {
			printf("Good No.%d\n", i);
			continue;
		}
		f = 1;
		for (j = 1; j <= 5; j++) {
			if (p[i][j] < 85) {
				f = 0;
				break;
			}
		}
		if (f)
			printf("Good No.%d\n", i);
	}
}

int main(void)
{
	int i, j;

#if 0
	srand(1);
	for (i = 1; i <= 4; i++)
		for (j = 1; j <= 5; j++)
			score[i][j] = 40+rand()%61;
#endif
	freopen("8.15.in", "r", stdin);
	setbuf(stdout, NULL);
	memset(score, 0, sizeof(score));
	for (i = 1; i <= 4; i++)
		for (j = 1; j <= 5; j++)
			scanf("%d", &score[i][j]);

	for (i = 1; i <= 4; i++) {
		for (j = 1; j <= 5; j++)
			printf("%2d ", score[i][j]);
		printf("\n");
	}

	printf("Average socre of class.1: %5.2lf\n", average_class(score, 1));
	fail(score);
	good(score);

	return 0;
}
