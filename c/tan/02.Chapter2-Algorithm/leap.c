#include <stdio.h>
#include <string.h>

int check_leap_year(int x)
{
	if (x % 4)
		return 0;

	if (x % 100)
		return 1;

	if (!(x % 400))
		return 1;

	//printf("x = %d\n", x);
	return 0;
}

int main(void)
{
	int year;
	int ret;

	for (year = 2000; year <= 2500; year++) {
		ret = check_leap_year(year);
		if (ret)
			printf("%d: leap year\n", year);
	}

	return 0;
}

	
