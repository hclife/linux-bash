#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define SIZE	64
#define LEN	sizeof(struct guest)

struct guest {
	int number;
	char name[16];
	int sum;
	char time[10];
	struct guest *next;
};

struct guest *head;

void insert(void)
{
	struct guest *p, *q, *in;

	//printf("insert\n");
	in = malloc(LEN);
	if (!in) {
		printf("malloc failed\n");
		return;
	}
	scanf("%d %s %d %s", &in->number, in->name,
	       &in->sum, in->time);
	in->next = NULL;
	//printf("%-5d%-10s%-5d%-10s\n", in->number,
	//	in->name, in->sum, in->time);
	
	if (!head) {
		head = in;
		return;
	}
	for (p = q = head; p; q = p, p = p->next) {
		if (p->number == in->number) {
			//printf("same number\n");
			return;
		}
	}
	q->next = in;
}

void delete(void)
{
	struct guest *p, *q;
	int num;

	//printf("delete\n");
	scanf("%d", &num);
	if (head->number == num) {
		p = head;
		head = head->next;
		free(p);
		return;
	}

	for (p = q = head; p; q = p, p = p->next) {
		if (p->number == num) {
			q->next = p->next;
			free(p);
			return;
		}
	}
}

void search(void)
{
	struct guest *p;
	int num;

	scanf("%d", &num);
	//printf("search %d\n", num);
	for (p = head; p; p = p->next) {
		if (p->number == num) {
			printf("%-5d%-10s%-5d%-10s\n", p->number,
					p->name, p->sum, p->time);
			return;
		}
	}
	//printf("no match\n");
}

void update(void)
{
	struct guest *p, *in;
	int flag;

	//printf("update\n");
	in = malloc(LEN);
	if (!in) {
		printf("malloc failed\n");
		return;
	}
	scanf("%d %s %d %s", &in->number, in->name,
	       &in->sum, in->time);

	for (p = head; p; p = p->next) {
		if (p->number == in->number) {
			strcpy(p->name, in->name);
			strcpy(p->time, in->time);
			p->sum = in->sum;
			return;
		}
	}
}

void show(void)
{
	struct guest *p;

	//printf("show\n");
	if (!head)
		return;
	for (p = head; p; p = p->next) {
		printf("%-5d%-10s%-5d%-10s\n", p->number,
			p->name, p->sum, p->time);
	}
}

void destroy(void)
{
	struct guest *p, *q;

	for (p = q = head; p; q = p, p = p->next, free(q)) {}
	head = NULL;
}

int main(void)
{
	int i = -1;

	freopen("13.3.in", "r", stdin);
	setbuf(stdout, NULL);
	head = NULL;
	while (i) {
		scanf("%d", &i);
		switch (i) {
		case 0:
			//printf("None\n");
			break;
		case 1:
			insert();
			break;
		case 2:
			search();
			break;
		case 3:
			update();
			break;
		case 4:
			delete();
			break;
		case 5:
			show();
			break;
		default:
			printf("Wrong input\n");
			break;
		}
	}
	destroy();
	//show();

	return 0;
}
