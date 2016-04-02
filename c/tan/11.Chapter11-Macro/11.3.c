#include <stdio.h>
#define PI	3.1415926
#define S(r)	PI*r*r
int main(void)
{
	double a = 3.6;
	double area = S(a);

	printf("r = %lf\narea=%lf\n", a, area);
	return 0;
}

