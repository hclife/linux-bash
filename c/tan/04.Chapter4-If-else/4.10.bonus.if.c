#include <stdio.h>

int main(void)
{
	int I;
	double bonus;

	printf("Please input the profit: ");
	scanf("%d", &I);
	if (I < 0) {
		printf("There is no profit!\n");
		return -1;
	}

	if (I <= 100000)
		bonus = I * 0.1;
	else if (I <= 200000)
		bonus = 100000 * 0.1 + (I - 100000) * 0.075;
	else if (I <= 400000)
		bonus = 100000 * 0.1 + 100000 * 0.075 + (I - 200000) * 0.05;
	else if (I <= 600000)
		bonus = 100000 * 0.1 + 100000 * 0.075 + 200000 * 0.05 +
			(I - 400000) * 0.03;
	else if (I <= 1000000)
		bonus = 100000 * 0.1 + 100000 * 0.075 + 200000 * 0.05 +
			200000 * 0.03 + (I - 600000) * 0.015;
	else
		bonus = 100000 * 0.1 + 100000 * 0.075 + 200000 * 0.05 +
			200000 * 0.03 + 400000 * 0.015 + (I - 1000000) * 0.01;

	printf("%.2lf\n", bonus);

	return 0;
}
