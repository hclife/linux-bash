#include <stdio.h>

#define IN	0
#define OUT	1
#define MAX	1024

main()
{
	int c, i, j, k, max, state = OUT;
	int word[MAX] = {0};

	max = i = j = k = 0;
	while ((c=getchar())!=EOF) {
		if (c==' '||c=='\n'||c=='\t') {
			if (state==IN) state=OUT;
		} else if (state==OUT) {
			word[++i]++;
			state=IN;
		} else {word[i]++;}
	}

	for (j = 1; j <= i; j++)
		if (max < word[j])
			max = word[j];

	for (k = 1; k <= max; k++) {
		for (j = 1; j <= i; j++) {
			if (k < max-word[j]+1) putchar(' ');
			else putchar('|');
		}
		putchar('\n');
	}
}
