#include <stdio.h>

main()
{
	int sp, tab, nl, c;

	sp=tab=nl=0;
	while ((c=getchar())!=EOF) {
		if (c==' ')  ++sp;
		if (c=='\t') ++tab;
		if (c=='\n') ++nl;
	}
	printf("%d %d %d\n", sp, tab, nl);
}
