#include <stdio.h>

int main(void)
{
	int I, c;
	double bonus;

	printf("Please input the profit: ");
	scanf("%d", &I);
	if (I < 0) {
		printf("There is no profit!\n");
		return -1;
	}

	c = I / 100000;
	switch (c) {
		case 0:
			bonus = I * 0.1;
			break;
		case 1:
			bonus = 100000 * 0.1 + (I - 100000) * 0.075;
			break;
		case 2:
		case 3:
			bonus = 100000 * 0.1 + 100000 * 0.075 + (I - 200000) * 0.05;
			break;
		case 4:
		case 5:
			bonus = 100000 * 0.1 + 100000 * 0.075 + 200000 * 0.05 +
				(I - 400000) * 0.03;
			break;
		case 6:
		case 7:
		case 8:
		case 9:
			bonus = 100000 * 0.1 + 100000 * 0.075 + 200000 * 0.05 +
				200000 * 0.03 + (I - 600000) * 0.015;
			break;
		default:
			bonus = 100000 * 0.1 + 100000 * 0.075 + 200000 * 0.05 +
				200000 * 0.03 + 400000 * 0.015 + (I - 1000000) * 0.01;
	}

	printf("%.2lf\n", bonus);

	return 0;
}
