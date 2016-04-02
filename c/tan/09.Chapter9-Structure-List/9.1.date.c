#include <stdio.h>

struct date {
	int year, month, date;
};

int mdays[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int check_leap_year(int x)
{
	if (x % 4)
		return 0;

	if (x % 100)
		return 1;

	if (x % 400)
		return 0;

	return 1;
}

int days(struct date *p)
{
	int i, r;

	r = 0;
	for (i = 0; i < p->month; i++)
		r += mdays[i];
	return r + p->date;
}

int main(void)
{
	struct date d;
	int r;

	while (1) {
		scanf("%d %d %d", &d.year, &d.month, &d.date);
		if (d.year < 0) {
			printf("-1\n");
			continue;
		}

		if (d.month < 1 || d.month > 12) {
			printf("-2\n");
			continue;
		}

		if (check_leap_year(d.year))
			mdays[2] = 29;
		else
			mdays[2] = 28;

		if (d.date < 1 || d.date > mdays[d.month]) {
			printf("-3\n");
			continue;
		}

		r = days(&d);
		printf("%d\n", r);
	}

	return 0;
}
