#include <stdio.h>
#include <string.h>

#define MAX 1024
char buf[MAX];

int string_length(const char *s)
{
	int i;
	for (i = 0; *(s+i); i++);
	return i;
}

int main(void)
{
	scanf("%s", buf);
	printf("%d\n", string_length(buf));
	return 0;
}
