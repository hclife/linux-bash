#include <stdio.h>
#include <string.h>

int check_prime(int n)
{
	int i;

	if (n <= 1)
		return 0;

	if (n == 2)
		return 1;

	for (i = 2; i * i <= n; i++)
		if (n % i == 0)
			return 0;
	return 1;
}


int main(void)
{
	int num[128];
	int N = 100;
	int i, j, ret;

	for (i = 1; i <= N; i++)
		num[i] = 1;

	num[1] = 0;
	for (i = 2; i <= N; i++) {
		if (!num[i])
			continue;
		ret = check_prime(i);
		if (!ret) {
			num[i] = 0;
			continue;
		}

		for (j = 2; i * j <= N; j++) {
			//printf("main: put num[%d] to 0\n", i * j);
			num[i * j] = 0;
		}
	}

	for (i = 1; i <= N; i++)
		if (num[i])
			printf("%d ", i);
	printf("\n");


	return 0;
}


