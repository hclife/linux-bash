#include <stdio.h>

int main(void)
{
	char *name[] = {"Follow me", "Basic", "Great Wal",
			"FORTRAN", "Computer design"};
	char **p;
	int i;

	for (i = 0; i < 5; i++) {
		p = name + i;
		printf("%s\n", *p);
	}
	return 0;
}
