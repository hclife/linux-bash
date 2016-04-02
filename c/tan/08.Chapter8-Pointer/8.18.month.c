#include <stdio.h>
#include <string.h>

int main(void)
{
	int n;
	const char *month[] = {0, "January", "February", "March",
				  "April", "May", "June", "July",
				  "August", "September", "October",
				  "November", "December"};
	while (1) {
		scanf("%d", &n);
		if (n < 1 || n > 12) {
			printf("input error\n");
			continue;
		}
		printf("%s\n", month[n]);
	}

	return 0;
}
