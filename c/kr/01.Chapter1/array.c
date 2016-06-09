#include <stdio.h>

main()
{
	int c, i, white, other;
	int digit[10];

	white = other = 0;
	for (i = 0; i < 10; i++) digit[i] = 0;
	while ((c = getchar())!=EOF) {
		if (c >= '0' && c <= '9') digit[c-'0']++;
		else if (c == ' ' || c == '\n' || c == '\t') white++;
		else other++;
	}
	printf("digits =");
	for (i = 0; i < 10; i++) printf(" %d", digit[i]);
	printf(", white space = %d, other = %d\n", white, other);
}
