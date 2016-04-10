/* entab */

#include <stdio.h>
#include <string.h>

#define MAX	1024
#define TAB	8

int get(char s[])
{
	int c,i;
	for (i=0;(c=getchar())!=EOF;i++)
		if ((s[i]=c)=='\n') break;
	if (i) s[++i]=0;
	return i;
}

main()
{
	int len;
	char line[MAX]={0};
	freopen("1-21.in","r",stdin);
	freopen("1-21.out","w",stdout);
	while (len=get(line)) {
		printf("%s",line);
	}
}
