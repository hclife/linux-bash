#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

void check(int *);

int main(void)
{
	int *pt, i;

	pt = (int *)malloc(5 * sizeof(int));
	for (i = 0; i < 5; i++)
		scanf("%d", pt+i);
	check(pt);
	free(pt);

	return 0;
}

void check(int *p)
{
	int i;

	printf("They are fail: ");
	for (i = 0; i < 5; i++)
		if (p[i] < 60)
			printf("%d ", p[i]);
	printf("\n");
}
