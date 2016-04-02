#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main(void)
{
	int letter, space, number, other;
	int p;
	int i;
	char a[128];

	memset(a, 0, sizeof(a));
	p = 0;
	while (1) {
		a[p] = getchar();
		//printf("a[%d] = %c\n", p, a[p]);
		if (a[p] == '\n')
			break;
		p++;
	}

	//printf("p = %d, a = %s\n", p, a);

	letter = space = number = other = 0;
	for (i = 0; i < p; i++) {
		if (a[i] >= 'a' && a[i] <= 'z') {
			letter++;
			continue;
		}

		if (a[i] >= 'A' && a[i] <= 'Z') {
			letter++;
			continue;
		}

		if (a[i] == ' ') {
			space++;
			continue;
		}

		if (a[i] >= '0' && a[i] <= '9') {
			number++;
			continue;
		}

		other++;
	}

	printf("letter = %d, space = %d, number = %d, other = %d\n",
		letter, space, number, other);


	return 0;
}
