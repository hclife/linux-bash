#include <stdio.h>

double power(double x, int n)
{
	if (!n)
		return 1.0f;
	if (n == 1)
		return x;
	
	return x * power(x, n-1);
}

int main(void)
{
	float money = 1000.0f;
	float fix_rate1 = 0.0414f;
	float fix_rate2 = 0.0468f;
	float fix_rate3 = 0.054f;
	float fix_rate5 = 0.0585f;
	float flex_rate = 0.0072f;
	float P1, P2, P3, P4, P5;

	P1 = money * (1 + fix_rate5) * 5;
	P2 = money * (1 + 2 * fix_rate2);
	P2 = P2 * (1 + 3 * fix_rate3);
	P3 = money * (1 + 3 * fix_rate3);
	P3 = P3 * (1 + 2 * fix_rate2);
	P4 = money * power(1 + fix_rate1, 5);
	P5 = money * power(1 + flex_rate / 4, 4 * 5);

	printf("P1 = %f\n", P1);
	printf("P2 = %f\n", P2);
	printf("P3 = %f\n", P3);
	printf("P4 = %f\n", P4);
	printf("P5 = %f\n", P5);

	return 0;
}


