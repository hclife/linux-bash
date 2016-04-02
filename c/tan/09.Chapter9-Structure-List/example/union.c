#include <stdio.h>

union date {
	int i;
	char ch;
	float f;
};

int main(void)
{
	union date a;
	a.i = 97;
	printf("%d\n", a.i);
	printf("%c\n", a.ch);
	printf("%f\n", a.f);
	printf("%u\n", sizeof(union date));

	return 0;
}
