#include <stdio.h>

int check_prime(int n)
{
	int i;

	if (n < 2)
		return 0;

	if (n < 4)
		return 1;

	for (i = 2; i * i <= n; i++)
		if (n % i == 0)
			return 0;

	return 1;
}

int main(void)
{
	int N, ret;

	scanf("%d", &N);
	ret = check_prime(N);
	if (ret > 0)
		printf("%d is a prime number.\n", N);
	else
		printf("%d is not a prime number.\n", N);

	return 0;
}


