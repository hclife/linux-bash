#include <stdio.h>

struct student {
	char name[20];
	float score;
	int num;
	long long st;
};

int main(void)
{
	printf("%u\n", sizeof(struct student));
	return 0;
}
