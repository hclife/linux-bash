#include <stdio.h>
#include <string.h>

#define MAX 1024

struct people {
	int num, exist;
	struct people *next;
};
int last;

void init(struct people p[], int n)
{
	int i;

	for (i = 1; i <= n; i++) {
		p[i].num = i;
		p[i].exist = 1;
		if (i < n)
			p[i].next = &p[i+1];
	}
	p[n].next = &p[1];
}

void print(struct people *p, int n)
{
	int i = 1;

	while (i <= n) {
		printf("No.%2d: %d\n", p->num, p->exist);
		i++;
		p = p->next;
	}
}

void visit(struct people *p, int x, int k, int n)
{
	if (k >= n)
		return;

	if (!p->exist) {
		visit(p->next, x, k, n);
		return;
	}

	if (x == 3) {
		printf("%d ", p->num);
		p->exist = 0;
		last = p->num;
		visit(p->next, 1, k+1, n);
		return;
	}
	visit(p->next, x+1, k, n);
}

int main(void)
{
	int N;
	struct people data[MAX] = {0};

	scanf("%d", &N);
	last = 0;
	init(data, N);
	//print(&data[1], N);
	visit(&data[1], 1, 0, N);
	//print(&data[1], N);
	//printf("main: laast = %d\n", last);
	printf("\nThe last is %d\n", last);

	return 0;
}

