#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main(void)
{
	int letter, space, number, other;
	int p;
	char *s;
	int i;
	int a[128];
	int s[128];

	memset(a, 0, sizeof(a));
	memset(s, 0, sizeof(s));
	//s = (char *)calloc(0, sizeof(char) * 128);
	//printf("sizeof(s) = %d\n", sizeof(s));
	//printf("strlen(s) = %d\n", strlen(s));

	p = 0;
	while (1) {
		s[p] = getchar();
		//printf("s[%d] = %c\n", p, s[p]);
		if (s[p] == '\n')
			break;
		p++;
	}

	printf("p = %d, s = %s\n", p, s);

	letter = space = number = other = 0;
	for (i = 0; i < p; i++) {
		if (s[i] >= 'a' && s[i] <= 'z') {
			letter++;
			continue;
		}

		if (s[i] >= 'A' && s[i] <= 'Z') {
			letter++;
			continue;
		}

		if (s[i] == ' ') {
			space++;
			continue;
		}

		if (s[i] >= '0' && s[i] <= '9') {
			number++;
			continue;
		}

		other++;
	}

	printf("letter = %d, space = %d, number = %d, other = %d\n",
		letter, space, number, other);

	if (s)
		free(s);

	return 0;
}
