#include <stdio.h>
#include <string.h>

int bsearch_loop(int array[], int low, int high, int target)
{
	int mid;

	while (low <= high) {
		mid = (low + high) / 2;
		if (target < array[mid]) {
			high = mid - 1;
			continue;
		}

		if (target > array[mid]) {
			low = mid + 1;
			continue;
		}

		return mid;
	}

	return -1;
}

int bsearch_recurse(int array[], int low, int high, int target)
{
	int mid = (low + high) / 2;

	if (low > high)
		return -1;

	if (array[mid] == target)
		return mid;

	if (target < array[mid])
		return bsearch_recurse(array, low, mid-1, target);

	return bsearch_recurse(array, mid+1, high, target);
}


int main(void)
{
	int data[11] = {0, 10, 12, 15, 16, 19, 20, 27, 48, 50, 60};
	int ret, n;

	scanf("%d", &n);

#if 0
	ret = bsearch_loop(data, 1, 10, n); 
#else
	ret = bsearch_recurse(data, 1, 10, n);
#endif
	if (ret < 0) {
		printf("%d\n", ret);
		return ret;
	}

	printf("%d\n", ret);

	

	return 0;
}
