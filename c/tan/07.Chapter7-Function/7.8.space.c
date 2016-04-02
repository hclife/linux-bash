#include <stdio.h>
#include <string.h>

void print_num(int n)
{
	int i, r;
	int num[6];

	memset(num, 0, sizeof(num));
	i = 5;
	while (n > 0) {
		r = n % 10;
		n /= 10;
		//printf("%d\n", r);
		num[--i] = r;
	}

	for (i = 1; i < 4; i++)
		printf("%d ", num[i]);
	printf("%d\n", num[i]);
}

int main(void)
{
	int N;

	scanf("%d", &N);
	if (N < 1000 || N >= 10000) {
		printf("You should input a 4-digit number.\n");
		return 0;
	}

	print_num(N);
	return 0;
}
