#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define LEN sizeof(struct student)

struct student {
	int num;
	char *name;
	char *sex;
	int age;
	struct student *next;
};

struct student *create(void)
{
	struct student *p1 = malloc(LEN);
	struct student *p2 = malloc(LEN);
	struct student *p3 = malloc(LEN);
	struct student *p4 = malloc(LEN);
	struct student *p5 = malloc(LEN);
	struct student *p6 = malloc(LEN);

	p1->num = 1001; p1->name = "Wang"; p1->sex = "male"; p1->age = 20; p1->next = p2;
	p2->num = 1056; p2->name = "Lee";  p2->sex = "male"; p2->age = 21; p2->next = p3;
	p3->num = 1037; p3->name = "Zhao"; p3->sex = "male"; p3->age = 20; p3->next = p4;
	p4->num = 1028; p4->name = "Li"; p4->sex = "female"; p4->age = 19; p4->next = p5;
	p5->num = 1049; p5->name = "Sun"; p5->sex = "male"; p5->age = 22; p5->next = p6;
	p6->num = 1100; p6->name = "Yang"; p6->sex = "female"; p6->age = 20; p6->next = NULL;

	return p1;
}

void print(struct student *head)
{
	struct student *p;
	for (p = head; p; p = p->next)
		printf("%d: %s\t%s\t%d\n", p->num, p->name, p->sex, p->age);
}

struct student *check(struct student *head, int age)
{
	struct student *prev, *p, *q;
	for (prev = NULL, p = head; p;) {
		if (p->age != age) {
			prev = p;
			p = p->next;
			continue;
		}

		if (!prev) {
			head = p->next;
			free(p);
			p = head;
			continue;
		}

		prev->next = p->next;
		free(p);
		p = prev->next;
	}
	return head;
}

int main(void)
{
	int age_in;
	struct student *list = create();
	print(list);
	while (1) {
		scanf("%d", &age_in);
		list = check(list, age_in);
		print(list);
		if (!list) {
			printf("empty\n");
			break;
		}
	}

	return 0;
}

