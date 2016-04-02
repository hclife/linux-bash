#include <stdio.h>
#include <string.h>

int N, M;
int data[16][8];
double avg[16];

double average_of_student(int n)
{
	double val;
	int i, sum = 0;

	for (i = 1; i <= M; i++)
		sum += data[n][i];
	val = (double)sum / (double)M;

	return val;
}

double average_of_class(int m)
{
	double val;
	int i, sum = 0;

	for (i = 1; i <= N; i++)
		sum += data[i][m];
	val = (double)sum / (double)N;

	return val;
}

void find_highest(void)
{
	int i, j;
	int max, maxi, maxj;

	max = maxi = maxj = -1;
	for (i = 1; i <= N; i++) {
		for (j = 1; j <= M; j++) {
			if (max < data[i][j]) {
				max = data[i][j];
				maxi = i;
				maxj = j;
			}
		}
	}
	printf("The %dth student's %dth class is the highest: %lf\n", maxi, maxj, max);
}

double square_dist(void)
{
	int i, j;
	double A, B;

	A = 0.0f;
	for (i = 1; i <= N; i++)
		A += average_of_student(i) * average_of_student(i);

	B = 0.0f;
	for (i = 1; i <= N; i++)
		B += average_of_student(i);

	return A / (double)N - (B * B) / (double)(N * N);
}

int main(void)
{
	int i, j, k;
	double sigma;

	freopen("score.txt", "r", stdin);
	setbuf(stdout, NULL);
	scanf("%d %d", &N, &M);
	memset(data, 0, sizeof(data));
	memset(avg, 0.0f, sizeof(avg));
	for (i = 1; i <= N; i++)
		for (j = 1; j <= M; j++)
			scanf("%d", &data[i][j]);

#if 0
	printf("N = %d  M = %d\n", N, M);
	for (i = 1; i <= N; i++) {
		for (j = 1; j <= M; j++)
			printf("%d ", data[i][j]);
		printf("\n");
	}
#endif

	for (i = 1; i <= N; i++)
		printf("%2dth student's average score is %lf\n", i, average_of_student(i));

	for (i = 1; i <= M; i++)
		printf("%2dth class' average score is %lf\n", i, average_of_class(i));

	find_highest();
	sigma = square_dist();
	printf("The square distance of average score is %lf\n", sigma);

	return 0;
}
