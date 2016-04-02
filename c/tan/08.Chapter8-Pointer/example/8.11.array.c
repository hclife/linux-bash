#include <stdio.h>

int main(void)
{
	int a[3][4] = {1, 3, 5, 7, 9, 11, 13, 15, 17, 19, 21, 23};
	printf("0x%08x, 0x%08x\n", a, *a);
	printf("0x%08x, 0x%08x\n", a[0], *(a+0));
	printf("0x%08x, 0x%08x\n", &a[0], &a[0][0]);
	printf("0x%08x, 0x%08x\n", a[1], a+1);
	printf("0x%08x, 0x%08x\n", &a[1][0], *(a+1)+0);
	printf("0x%08x, 0x%08x\n", a[2], *(a+2));
	printf("0x%08x, 0x%08x\n", &a[2], a+2);
	printf("0x%08x, 0x%08x\n", a[1][0], *(*(a+1)+0));
	printf("0x%08x, 0x%08x\n", *a[2], *(*(a+2)+0));

	return 0;
}
