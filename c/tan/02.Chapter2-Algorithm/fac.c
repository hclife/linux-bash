#include <stdio.h>

int main(void)
{
	int i, t;

	t = 1;
	i = 2;
	while (i <= 5) {
		t = t * i;
		i++;
	}

	printf("%d\n", t);
	return 0;
}
