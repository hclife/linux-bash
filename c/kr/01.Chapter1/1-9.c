#include <stdio.h>

main()
{
	int c, sp = 0;

	while ((c=getchar())!=EOF) {
		if (c!=' ') {
			putchar(c);
			sp = 0;
			continue;
		}
		if (sp) continue;
		putchar(c);
		sp = 1;
	}
}
