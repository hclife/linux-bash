/* This is to print horizontal histogram of input words */
#include <stdio.h>

#define MAX_HIST	15	/* max length of histogram */
#define MAX_WORD	11	/* max length of a word */
#define IN		1	/* now inside a word */
#define OUT		0	/* now outside a word */

dump(int a[])
{
	int i;

	for (i = 0; i < MAX_WORD; i++)
		printf("%d ", a[i]);
	printf("\n");
}

main()
{
	int c, i, nc, state;
	int len;		/* length of each bar */
	int max_value;		/* maximum value of word length */
	int overflow;		/* number of overflow words */
	int wl[MAX_WORD];	/* word length counters */

	state = OUT;
	nc = overflow = 0;
	for (i = 0; i < MAX_WORD; i++)
		wl[i] = 0;
	i = 0;
	while ((c = getchar()) != EOF) {
		if (c == ' ' || c == '\n' || c == '\t') {
			state = OUT;
			if (nc > 0) {
				wl[++i] = nc;
				if (nc >= MAX_WORD) overflow++;
			}
			nc = 0;
		} else if (state == OUT) {
			state = IN;
			nc = 1;	/* beginning of a new word */
		} else {
			nc++;	/* inside of a word */
		}
	}
	//dump(wl);

	max_value = 0;
	for (i = 1; i < MAX_WORD; i++)
		if (max_value < wl[i])
			max_value = wl[i];

	for (i = 1; i < MAX_WORD; i++) {
		if (!wl[i]) break;
		printf("%5d - %5d : ", i, wl[i]);
		if (wl[i] > 0) {
			if ((len = wl[i] * MAX_HIST / max_value) <= 0)
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
	if (overflow > 0)
		printf("There are %d words >= %d\n", overflow, MAX_WORD);
}



