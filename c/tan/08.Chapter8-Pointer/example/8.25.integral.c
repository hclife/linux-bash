#include <stdio.h>
#include <math.h>

float integral(float a, float b, float (*func)(float));
float F1(float);
float F2(float);
float F3(float);
float F4(float);
float F5(float);

int main(void)
{
	float a, b;
	int n;

	printf("Please input range: ");
	scanf("%f %f", &a, &b);
	printf("Please input mode (1-5): ");
	scanf("%d", &n);
	//printf("%.4f, %.4f\n", a, b);
	switch (n) {
	case 1:
		printf("F1 ");
		integral(a, b, F1);
		break;
	case 2:
		printf("F2 ");
		integral(a, b, F2);
		break;
	case 3:
		printf("F3 ");
		integral(a, b, F3);
		break;
	case 4:
		printf("F4 ");
		integral(a, b, F4);
		break;
	case 5:
		printf("F5 ");
		integral(a, b, F5);
		break;
	default:
		printf("mode %d not supported\n", n);
		return -1;
	}

	return 0;
}

float integral(float a, float b, float (*func)(float))
{
	float r = (*func)(b) - (*func)(a);
	printf("integral: %.4f\n", r);
}

float F1(float x)
{
	float r = (1.0f/2.0f) * x * x + x;
	return r;
}

float F2(float x)
{
	float r = x * x + 3.0f * x;
	return r;
}

float F3(float x)
{
	float r = powf(2.718f, x);
	return r;
}

float F4(float x)
{
	float r = 1.0f/3.0f * x * x * x + x * x + x;
	return r;
}

float F5(float x)
{
	float r = 1.0f/4.0f * x * x * x * x;
	return r;
}
