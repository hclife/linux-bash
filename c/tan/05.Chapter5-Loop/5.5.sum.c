#include <stdio.h>
#include <string.h>

int main(void)
{
	int a, n;
	long long num, sum;

	printf("Please input a and n: ");
	scanf("%d %d", &a, &n);

	num = a;
	sum = 0;
	while (n--) {
		//printf("num = %lld\n", num);
		sum += num;
		num *= 10;
		num += a;
	}
	printf("%lld\n", sum);

	return 0;
}
