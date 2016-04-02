#include <stdio.h>

int main(void)
{
	unsigned short price = 50;
	unsigned short prace = -1;
	char ch = '?';
	unsigned char c;
	char d = 255;
	unsigned char e = 255;
	const float a = 3.14159f;
	double val = 1.0f;
	int i = -1;

	printf("%u\n", price);
	printf("%d\n", prace);
	printf("%d %c\n", ch, ch);
	printf("d: %d %d\n", d, d);
	printf("e: %d %d\n", e, e);
	printf("a: %f\n", a);
	printf("%d\n", -5/3);

	for (c = 128; c <= 130; c++)
		printf("%d %c\n", c, c);

	printf("%20.15f\n", val/3);
	printf("%55.50f\n", val/3);
	val = 10000.0f / 3.0f;
	printf("%f\n", val);
	printf("%-25.15f,%25.15f\n", val, val);
	val = 12345678954321.0f;
	printf("val: %f\t%e\t%g\n", val, val, val);

	printf("%e\n", 123.456f);
	printf("%E\n", 123.456f);
	printf("%13.2e\n", 123.456);
	printf("%d\t%o\t%x\n",i, i, i);
	printf("%f%%\n", 1.0/3);

	return 0;
}
	
