#include <stdio.h>

int bsearch_recursive(int array[], int low, int high, int target)
{
	int mid = (low + high) / 2;

	if (low > high)
		return -1;

	if (array[mid] == target)
		return mid;

	if (target < array[mid])
		return bsearch_recursive(array, low, mid-1, target);

	return bsearch_recursive(array, mid+1, high, target);
}

int main(void)
{
#if 0
	int data[16] = {0,
			1,  5,  6,  12, 14,
			18, 19, 23, 25, 28,
			34, 35, 38, 48, 50};
#else
	int data[16] = {0, 1, 3, 4, 5, 6, 8,
			12, 23, 34, 44, 45,
			56, 57, 58, 68};
#endif
	int ret, N;

	scanf("%d", &N);

	ret = bsearch_recursive(data, 1, 15, N);
	if (ret < 0)
		printf("No such number %d\n", N);
	else
		printf("%d\n", ret);

	return 0;
}
