#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define SIZE 16

struct tax {
	int left, right;
	int tax, deduct;
} list[SIZE];

double cut, salary;
double disp(double base)
{
	int i;

	if (base <= 0)
		return 0;

	for (i = 1; i < 10; i++)
		if (base < (double)list[i].left)
			break;

	return base*list[i-1].tax/100.0f-list[i-1].deduct;
}

int main(void)
{
	int i, j, r;
	FILE *fp = fopen("tax.in", "r");
	if (!fp) {
		printf("open read fail\n");
		exit(1);
	}

	scanf("%lf %lf", &salary, &cut);
	memset(list, 0, sizeof(list));
	for (i = 1; i <= 9; i++) {
		r = fscanf(fp, "%d %d %d %d", &list[i].left, &list[i].right,
					      &list[i].tax, &list[i].deduct);
		if (r != 4) {
			printf("fscanf error: %d\n", r);
			fclose(fp);
			exit(2);
		}
	}

#if 0
	printf("The tax list is:\n");
	for (i = 1; i < 10; i++)
		printf("%d\t%d\t%d\t%d\n", list[i].left, list[i].right,
					   list[i].tax, list[i].deduct);
#endif

	//printf("The personal tax should pay is %.2lf.\n", disp(salary-cut));
	printf("%.2lf\n", disp(salary-cut));

	if (fp) {
		fclose(fp);
		fp = NULL;
	}

	return 0;
}
