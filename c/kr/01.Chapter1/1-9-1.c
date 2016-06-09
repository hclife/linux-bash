#include <stdio.h>

#define NON_BLANK 'A'

main()
{
	int c, lastc;
	
	lastc = NON_BLANK;
	while ((c=getchar())!=EOF) {
		if (c!=' '||lastc!=' ') putchar(c);
		lastc=c;
	}
}
