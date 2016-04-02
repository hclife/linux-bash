#include <stdio.h>

int cube(int n)
{
	return n * n * n;
}

int main(void)
{
	int i, j, k;
	int n;
	int a, b, c;

	for (n = 100; n < 1000; n++) {
#ifdef DEBUG
		printf("n = %d\n", n);
#endif

		a = n / 100;
#ifdef DEBUG
		printf("a = %d\n", a);
#endif
		
		b = n % 100;
		b /= 10;
#ifdef DEBUG
		printf("b = %d\n", b);
#endif

		c = n % 10;
#ifdef DEBUG
		printf("c = %d\n", c);
#endif

		if (n == cube(a) + cube(b) + cube(c))
			printf("%d\n", n);
	}

	return 0;
}
