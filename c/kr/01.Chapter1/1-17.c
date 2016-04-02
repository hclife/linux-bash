#include <stdio.h>

#define MAX_LINE	1000
#define LONG_LINE	80

int get_line(char line[], int max_line);

main()
{
	int len, max;
	char line[MAX_LINE], longest[MAX_LINE];
	freopen("1-17.in", "r", stdin);
	while ((len = get_line(line, MAX_LINE)) > 0)
		if (len > LONG_LINE) printf("%s", line);
}

int get_line(char s[], int lim)
{
	int c, i;
	for (i = 0; i < lim-1 && (c=getchar())!=EOF &&
	     c != '\n'; i++) s[i] = c;
	if (c == '\n') s[i++] = c;
	s[i] = 0;
	return i;
}
