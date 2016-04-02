#include <stdio.h>
#include <string.h>

int main(void)
{
	int data[100];
	int N;
	int i, j;
	int temp;

	memset(data, 0, sizeof(data));
	scanf("%d", &N);
	for (i = 1; i <= N; i++)
		scanf("%d", &data[i]);

#if 1
	printf("The original order: ");
	for (i = 1; i <= N; i++)
		printf("%d ", data[i]);
	printf("\n");
#endif

	for (i = 1; i <= N/2; i++) {
		temp = data[i];
		data[i] = data[N-i+1];
		data[N-i+1] = temp;
	}

#if 1
	printf("The reversed order: ");
	for (i = 1; i <= N; i++)
		printf("%d ", data[i]);
	printf("\n");
#endif


	return 0;
}
