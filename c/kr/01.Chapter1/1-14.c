/* Print horizontal histogram of different characters frequency */
#include <stdio.h>
#include <ctype.h>

#define MAX_HIST	15	/* max length of histogram */
#define MAX_CHAR	128	/* max different characters */

main()
{
	int c, i, len, max_value;
	int cc[MAX_CHAR];

	for (i = 0; i < MAX_CHAR; i++)
		cc[i] = 0;
	while ((c = getchar()) != EOF)
		if (c < MAX_CHAR) cc[c]++;

	max_value = 0;
	for (i = 1; i < MAX_CHAR; i++)
		if (max_value < cc[i])
			max_value = cc[i];

	for (i = 1; i < MAX_CHAR; i++) {
		if (!isprint(i) || !cc[i]) continue;
		printf("%5d - %c - %5d : ", i, i, cc[i]);
		if (cc[i] > 0) {
			if ((len = cc[i] * MAX_HIST / max_value) <= 0)
				len = 1;
		} else {
			len = 0;
		}

		while (len > 0) {
			putchar('*');
			len--;
		}
		putchar('\n');
	}
}
