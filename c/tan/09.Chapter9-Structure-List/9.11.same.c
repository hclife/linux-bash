#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define LEN sizeof(struct student)

struct student {
	int num;
	float score;
	struct student *next;
};

struct student *createa(void)
{
	struct student *p1 = malloc(LEN);
	struct student *p2 = malloc(LEN);
	struct student *p3 = malloc(LEN);
	struct student *p4 = malloc(LEN);
	struct student *p5 = malloc(LEN);
	struct student *p6 = malloc(LEN);

	p1->num = 1001; p1->score = 73.5f; p1->next = p2;
	p2->num = 1056; p2->score = 56.0f; p2->next = p3;
	p3->num = 1037; p3->score = 68.0f; p3->next = p4;
	p4->num = 1028; p4->score = 70.0f; p4->next = p5;
	p5->num = 1049; p5->score = 65.5f; p5->next = p6;
	p6->num = 1100; p6->score = 84.0f; p6->next = NULL;

	return p1;
}

struct student *createb(void)
{
	struct student *p1 = malloc(LEN);
	struct student *p2 = malloc(LEN);
	struct student *p3 = malloc(LEN);

	p1->num = 1001; p1->score = 66.0f; p1->next = p2;
        p2->num = 1028; p2->score = 85.0f; p2->next = p3;
	p3->num = 1100; p3->score = 92.5f; p3->next = NULL;

	return p1;
}

void print(struct student *head)
{
	struct student *p;

	printf("print list:\n");
	for (p = head; p; p = p->next)
		printf("num:%d\tscore:%5.1f\n", p->num, p->score);
}

struct student *scan(struct student *head, struct student *base)
{
	struct student *p, *prev, *q, *tmp;
	int f;

	for (prev = NULL, p = head; p;) {
		f = 0;
		for (q = base; q; q = q->next) {
			if (q->num == p->num) {
				f = 1;
				break;
			}
		}
		if (!f) {
			prev = p;
			p = p->next;
			continue;
		}

		tmp = p->next;
		free(p);
		p = tmp;
		if (prev)
			prev->next = p;
		else
			head = p;
	}

	return head;
}

int main(void)
{
	struct student *a = createa();
	struct student *b = createb();

	//print(a);
	//print(b);
	a = scan(a, b);
	print(a);

	return 0;
}
