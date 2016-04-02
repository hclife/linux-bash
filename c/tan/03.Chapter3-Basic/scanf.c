#include <stdio.h>

int main(void)
{
	float a, b, c;
	int h, m, s;
	char c1, c2, c3;
	int x;
	char y;
	float z;

	//scanf("%f%f%f", &a, &b, &c);
	//scanf("a=%f,b=%f,c=%f", &a, &b, &c);
	//scanf("a=%f  b=%f  c=%f", &a, &b, &c);
	//printf("a = %f, b = %f, c = %f\n", a, b, c);

	//scanf("%d: %d: %d", &h, &m, &s);
	//printf("h = %d, m = %d, s = %d\n", h, m, s);

	//scanf("%c%c%c", &c1, &c2, &c3);
	//printf("c1 = %c, c2 = %c, c3 = %c\n", c1, c2, c3);

	scanf("%d%c%f", &x, &y, &z);
	printf("x = %d, y = %c, z = %f\n", x, y, z);

	return 0;
}
