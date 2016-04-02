#include <stdio.h>

int main(void)
{
	int m, s, i;
	int count, c;

	for (m = 2; m < 1000; m++) {
		s = 0;
		count = 0;
		for (i = 1; i < m; i++)
			if (!(m % i)) {
				count++;
				s += i;
			}
		if (s != m)
			continue;
		printf("%d its factors are ", m);
		c = 0;
		for (i = 1; i < m; i++) {
			if (!(m % i)) {
				c++;
				printf("%d", i);
				if (c < count)
					printf(",");
			}
		}
		printf("\n");
	}

	return 0;
}
