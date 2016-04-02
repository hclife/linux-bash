#include <stdio.h>
#include <string.h>
#include <math.h>

#define NUM  300
#define SIZE 303

struct student {
	int number;
	int score[4];
};

struct student stu[SIZE];
double ave[SIZE], sigma[SIZE];
int grade[16];
int N;

void draw(int g[]);
int accept_data(struct student s[], int g[]);
void show_data_all(struct student s[], int sum, int g[]);
void count(int *max, int *min, double *pass, double ave[],
	   double sigma[], struct student s[], int sum);
void show_data_final(int max, int min, double pass, double ave[],
		     double sigma[]);

void draw(int g[])
{
}

int accept_data(struct student s[], int g[])
{
	int i, tmp, a1, a2, flag;

	scanf("%d %d", &a1, &a2);
	scanf("%d", &N);
	i = 1;
	while (i <= N) {
		scanf("%d %d %d", &s[i].number,
		      &s[i].score[1], &s[i].score[2]);
		tmp = (int)(1.0f*a1/100*s[i].score[1] +
			    1.0f*a2/100*s[i].score[2]);
		s[i].score[3] = tmp;
		tmp = (s[i].score[3])/10;
		if (tmp == 10) g[10]++;
		else g[tmp]++;
		i++;
	}

	return N;
}

void show_data_all(struct student s[], int sum, int g[])
{
}


void count(int *max, int *min, double *pass, double ave[],
	   double sigma[], struct student s[], int sum)
{
	int i, j, pass_sum = 0;
	int total[4];
	double tmp;

	*max = *min = s[1].score[2];
	for (i = 1; i <= sum; i++) {
		if (s[i].score[2] >= 60)
			pass_sum++;
		if (*max < s[i].score[2])
			*max = s[i].score[2];
		if (*min > s[i].score[2])
			*min = s[i].score[2];
	}
	*pass = (1.0f*pass_sum/sum)*100;

	memset(total, 0, sizeof(total));
	for (i = 1; i <= 3; i++) {
		for (j = 1; j <= sum; j++)
			total[i] += s[j].score[i];
		ave[i] = total[i]/sum;
	}

	for (i = 1; i <= 3; i++) {
		sigma[i] = 0;
		for (j = 1; j <= sum; j++) {
			tmp = s[j].score[i] - ave[i];
			sigma[i] += tmp*tmp;
		}
		sigma[i] = sqrt(fabs(sigma[i])/sum);
	}
}

void show_data_final(int max, int min, double pass, double ave[],
		     double sigma[])
{
	int i;
	printf("pass ratio = %6.2f%% max = %d min = %d\n", pass, max, min);
	for (i = 1; i <= 3; i++)
		printf("%6.2f %6.2f\n", ave[i], sigma[i]);
}

void dump(struct student s[], int g[], int sum)
{
	int i;
	printf("dump student and grade information:\n");
	for (i = 1; i <= sum; i++) {
		printf("%d: %d %d %d\n", s[i].number, s[i].score[1],
					s[i].score[2], s[i].score[3]);
	}
	for (i = 10; i >= 0; i--) {
		if (!g[i]) continue;
		printf("Grade %d: %d\n", i, g[i]);
	}
}

int main(void)
{
	int sum, max, min;
	double pass = 0;

	freopen("13.2.in", "r", stdin);
	setbuf(stdout, NULL);
	memset(stu, 0, sizeof(stu));
	memset(ave, 0, sizeof(ave));
	memset(sigma, 0, sizeof(sigma));
	memset(grade, 0, sizeof(grade));
	sum = accept_data(stu, grade);
	//dump(stu, grade, sum);
	show_data_all(stu, sum, grade);
	count(&max, &min, &pass, ave, sigma, stu, sum);
	show_data_final(max, min, pass, ave, sigma);

	return 0;
}
