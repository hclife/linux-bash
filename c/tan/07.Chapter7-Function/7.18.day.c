#include <stdio.h>
#include <string.h>

int dayn[16] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int check_leap_year(int x)
{
	if (x % 4)
		return 0;

	if (x % 100)
		return 1;

	if (!(x % 400))
		return 1;

	return 0;
}

int get_date_sequence(int y, int m, int d)
{
	int ret, add, base;
	int i;

	add = 0;
	ret = check_leap_year(y);
	if (ret)
		add++;
	//printf("ret = %d\n", ret);

	if (m == 1)
		return d;

	if (m == 2) {
		if (d > dayn[2] + add)
			return -1;
		return dayn[1] + d;
	}

	if (d > dayn[m])
		return -2;

	base = add;
	for (i = 1; i < m; i++)
		base += dayn[i];
	return base + d;
}

int main(void)
{
	int year, month, day;
	int ret;

	printf("Please input date as year-month-day:\n");
	scanf("%d-%d-%d", &year, &month, &day);
	//printf("main: %d-%d-%d\n", year, month, day);

	if (month < 1 || month > 12) {
		printf("Input month error\n");
		return 0;
	}

	if (day < 1 || day > 31) {
		printf("Input day error\n");
		return 0;
	}

	ret = get_date_sequence(year, month, day);
	if (ret < 0) {
		printf("Input month-day error: %d\n", ret);
		return 0;
	}

	printf("The date is the %dth day of the year.\n", ret);

	return 0;
}
