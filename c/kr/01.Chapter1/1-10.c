#include <stdio.h>

main()
{
	int c;

	while ((c=getchar())!=EOF) {
		if (c=='\t') {
			printf("\\t");
			continue;
		}
		if (c=='\b') {
			printf("\\b");
			continue;
		}
		if (c=='\\') {
			printf("\\\\");
			continue;
		}
		putchar(c);
	}
}
