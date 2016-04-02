#include <stdio.h>
#include <stdlib.h>

char *my_malloc(int n)
{
	return malloc(n * sizeof(char));
}

void my_free(char *p)
{
	if (p) {
		free(p);
		p = NULL;
	}
}

int main(void)
{
	int i;
	char *p = my_malloc(10);

	if (!p) {
		printf("malloc fail\n");
		return -1;
	}

	p[0] = 'm';
	p[1] = 'a';
	p[2] = p[3] = 'l';
	p[4] = 'o';
	p[5] = 'c';
	printf("%s\n", p);
	my_free(p);

	return 0;
}
