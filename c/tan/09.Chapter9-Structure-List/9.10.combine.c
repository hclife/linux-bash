#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LEN sizeof(struct student)

struct student {
	int no;
	int num;
	float score;
	struct student *next;
};

struct student *createa(void)
{
	struct student *p1 = malloc(LEN);
	struct student *p2 = malloc(LEN);
	struct student *p3 = malloc(LEN);

	p1->no = 1; p1->num = 1001; p1->score = 73.5f; p1->next = p2;
	p2->no = 2; p2->num = 1056; p2->score = 56.0f; p2->next = p3;
	p3->no = 3; p3->num = 1037; p3->score = 68.0f; p3->next = NULL;

	return p1;
}

struct student *createb(void)
{
	struct student *p1 = malloc(LEN);
	struct student *p2 = malloc(LEN);
	struct student *p3 = malloc(LEN);

	p1->no = 4; p1->num = 1023; p1->score = 66.0f; p1->next = p2;
        p2->no = 5; p2->num = 1048; p2->score = 85.0f; p2->next = p3;
	p3->no = 6; p3->num = 1077; p3->score = 92.5f; p3->next = NULL;

	return p1;
}

void print(struct student *head)
{
	struct student *p;

	printf("print list:\n");
	for (p = head; p; p = p->next)
		printf("no:%d\tnum:%d\tscore:%5.1f\n", p->no, p->num, p->score);
}

struct student *combine(struct student *a, struct student *b)
{
	struct student *prev, *p;

	for (p = prev = a; p; prev = p, p = p->next);
	prev->next = b;
	return a;
}

struct student *sort(struct student *head)
{
	struct student *p, *q, *min_p, *min_q;;
	struct student *p_new, *prev_new, *head_new;

	prev_new = NULL;
	while (1) {
		int min_num = -1;
		for (p = head; p; p = p->next) {
			if (!p->no)
				continue;
			if (min_num < 0 || min_num > p->num) {
				min_num = p->num;
				min_p = p;
			}
		}
		if (min_num < 0)
			break;
		//printf("min_num = %d\n", min_num);
		p_new = malloc(LEN);
		if (!p_new) {
			//printf("malloc fail\n");
			return NULL;
		}
		p_new->no = min_p->no;
		p_new->num = min_p->num;
		p_new->score = min_p->score;
		min_p->no = 0;
		if (!prev_new) {
			head_new = p_new;
			prev_new = p_new;
			continue;
		}
		prev_new->next = p_new;
		prev_new = p_new;
	}
	if (prev_new) {
		//printf("tail\n");
		prev_new->next = NULL;
	}

	return head_new;
}

void list_free(struct student *head)
{
	struct student *p, *q;

	for (p = head; p; q = p->next, free(p), p = q);
}

int main(void)
{
	struct student *a = createa();
	struct student *b = createb();
	struct student *c, *n;

	//print(a);
	//print(b);

	c = combine(a, b);
	print(c);

	n = sort(c);
	print(n);

	list_free(n);
	list_free(c);

	return 0;
}
