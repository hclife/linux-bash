#include <stdio.h>

int main(void)
{
	unsigned short a,b,c;
	int n;

	scanf("%o %d", &a, &n);
	c = (a>>n)|(a<<(16-n));
	printf("a=%o,c=%o\n",a,c);

	return 0;
}



