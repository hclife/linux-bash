#include <stdio.h>

#define PI 3.14f

int main(void)
{
	int h;
	float r;
	float C, S, S2, V2, S3, V3;

	scanf("%f %d", &r, &h);
	C = 2 * PI * r;
	S = PI * r * r;
	S2 = 4 * S;
	V2 = 4 * PI * r * r * r / 3;
	S3 = 2 * S + C * h;
	//V3 = S * h;
	V3 = PI * r * r * h;
	printf("The round of cycle is     %.2f\n", C);
	printf("The size of cycle is      %.2f\n", S);
	printf("The size of ball is       %.2f\n", S2);
	printf("The volume of ball is     %.2f\n", V2);
	printf("The size of cylinder  is  %.2f\n", S3);
	printf("The volume of cylinder is %.2f\n", V3);

	return 0;
}
