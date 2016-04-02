#include <stdio.h>

int main(void)
{
	float score[][4] = {{60, 70, 80, 90},
			{56, 89, 67, 88},
			{34, 78, 90, 66}};
	float *search(float (*p)[4]);
	float *p;
	int i, j, k;

#if 0
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
#endif
	for (i = 0; i < 3; i++) {
		p = search(score+i);
		//printf("0x%08x\n", p);
		if (!p)
			continue;
		printf("No.%d scores are:", i);
		for (j = 0; j < 4; j++)
			printf("%5.2f\t", *(p+j));
		printf("\n");
	}

	return 0;
}

float *search(float (*p)[4])
{
	int i = 0;
	float *pt;

	pt = NULL;
	for (i = 0; i < 4; i++) {
		if (*(*p+i) < 60) {
			pt = *p;
		}
	}
	return pt;
}


