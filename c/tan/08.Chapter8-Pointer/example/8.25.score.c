#include <stdio.h>

int main(void)
{
	float score[][4] = {{60, 70, 80, 90},
			{56, 89, 67, 88},
			{34, 78, 90, 66}};
	float *search(float (*p)[4], int n);
	float *p;
	int i, k;

	printf("Enter the number of students: ");
	scanf("%d", &k);
	if (k < 0 || k > 2) {
		printf("input error\n");
		return -1;
	}
	printf("The scores of No.%d are:\n", k);
	p = search(score, k);
	for (i = 0; i < 4; i++)
		printf("%5.2f\t", *(p+i));
	printf("\n");

	return 0;
}

float *search(float (*p)[4], int n)
{
	return *(p+n);
}


