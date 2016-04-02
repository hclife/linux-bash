#include <stdio.h>
int main(void)
{
	unsigned a, b, c, d;

	scanf("%o", &a);
#if 0
	b = a >> 4;
	c = ~(~0 << 4);
	d = b & c;
#endif
	d = (a>>4)&~(~0<<4);
	printf("%o,%d\n%o,%d\n",a,a,d,d);

	return 0;
}
