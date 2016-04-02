#include <stdio.h>
#include <string.h>

struct student {
	int num;
	char name[32];
	double score[4];
};

void input(struct student p[])
{
	int i;

	//printf("input\n");
	for (i = 1; i <= 5; i++)
		scanf("%d %s %lf %lf %lf", &p[i].num, &p[i].name,
		      &p[i].score[1], &p[i].score[2], &p[i].score[3]);
}


void print(struct student p[])
{
	int i;

	//printf("print\n");
	for (i = 1; i <= 5; i++)
		printf("No.%d: %-5d %-7s %5.1lf %5.1lf %5.1lf\n",
		       i, p[i].num, p[i].name, p[i].score[1],
		       p[i].score[2], p[i].score[3]);
}

int main(void)
{
	struct student s[8];

	freopen("9.3.in", "r", stdin);
	setbuf(stdout, NULL);
	memset(s, 0, sizeof(s));
	input(s);
	print(s);

	return 0;
}

