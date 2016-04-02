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

int main(void)
{
	struct student *pt = create();
	print(pt);

	return 0;
}

