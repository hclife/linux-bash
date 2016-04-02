#include <stdio.h>
#include <string.h>

#define MAX	1024
char stra[MAX], strb[MAX], strc[MAX];

void swap(char **a, char **b)
{
	char *tmp = *a;
	*a = *b;
	*b = tmp;
}

void sort(char **a, char **b, char **c)
{
	if (strcmp(*a, *b) > 0) swap(a, b);
	if (strcmp(*a, *c) > 0) swap(a, c);
	if (strcmp(*b, *c) > 0) swap(b, c);
}

int main(void)
{
	char *pa, *pb, *pc;

	memset(stra, 0, sizeof(stra));
	memset(strb, 0, sizeof(strb));
	memset(strc, 0, sizeof(strc));

	fgets(stra, sizeof(stra), stdin);
	fgets(strb, sizeof(strb), stdin);
	fgets(strc, sizeof(strc), stdin);

	printf("in:\n");
	printf("%s", stra);
	printf("%s", strb);
	printf("%s", strc);

	pa = stra;
	pb = strb;
	pc = strc;
	sort(&pa, &pb, &pc);

	printf("out:\n");
	printf("%s", pa);
	printf("%s", pb);
	printf("%s", pc);

	return 0;
}
