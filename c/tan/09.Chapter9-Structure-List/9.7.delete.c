#include <stdio.h>
#include <stdlib.h>

#define LEN sizeof(struct student)
struct student {
	long long num;
	float score;
	struct student *next;
};
int n;

struct student *create(void)
{
	struct student *head, *p1, *p2;

	n = 0;
	head = NULL;
	p1 = p2 = malloc(LEN);
	scanf("%lld %f", &p1->num, &p1->score);
	while (p1->num) {
		n++;
		if (n == 1)
			head = p1;
		else
			p2->next = p1;
		p2 = p1;
		p1 = malloc(LEN);
		scanf("%lld %f", &p1->num, &p1->score);
	}
	p2->next = NULL;
	return head;
}

void print(struct student *p)
{
	while (p) {
		printf("num:%lld\tscore:%5.1f\n", p->num, p->score);
		p = p->next;
	}
}

struct student *delete(struct student *head, long long n)
{
	struct student *prev, *p, *q;;

	for (prev = NULL, p = head; p; prev = p, p = p->next)
		if (p->num == n)
			break;
	if (!p)
		return head;

	if (!prev) {
		q = p->next;
		free(p);
		return q;
	}

	prev->next = p->next;
	free(p);
	p = NULL;

	return head;
}

void insert(struct student *p, long long n, float s)
{
	struct student *pnew = malloc(LEN);
	struct student *prev = p;

	pnew->num = n;
	pnew->score = s;
	while (p) {
		prev = p;
		p = p->next;
	}
	prev->next = pnew;
	pnew->next = NULL;
}

int main(void)
{
	struct student *pt;
	int a, b, c, s;
	char ch;

	freopen("9.7.in", "r", stdin);
	pt = create();
	print(pt);
	printf("\n");

	pt = delete(pt, 1001LL);
	print(pt);
	printf("\n");

	insert(pt, 2014LL, 90.5f);
	print(pt);

	return 0;
}
