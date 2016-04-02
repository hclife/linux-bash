#include <stdio.h>

#define IN	0
#define OUT	1

main()
{
	int c, state = OUT;

	while ((c=getchar())!=EOF) {
		if (c==' '||c=='\n'||c=='\t') {
			if (state==IN) {
				putchar('\n');
				state=OUT;
			}
		} else if (state==OUT) {
			putchar('_');
			state=IN;
		} else {
			putchar('_');
		}
	}
}
