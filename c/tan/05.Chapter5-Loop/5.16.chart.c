#include <stdio.h>

int main(void)
{
	int i, j;
	int ch_num, sp_num;

	for (i = 1; i <= 4; i++) {
		ch_num = 2 * i - 1;
		sp_num = 4 - i;
		/* show space */
		for (j = 1; j <= sp_num; j++)
			printf(" ");
		/* show char */
		for (j = 1; j <= ch_num; j++)
			printf("*");
		printf("\n");
	}

	for (i = 1; i <= 3; i++) {
		ch_num = 7 - 2 * i;
		sp_num = i;
		/* show space */
		for (j = 1; j <= sp_num; j++)
			printf(" ");
		/* show char */
		for (j = 1; j <= ch_num; j++)
			printf("*");
		printf("\n");
	}

	return 0;
}
