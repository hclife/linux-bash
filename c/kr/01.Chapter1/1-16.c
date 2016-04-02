#include <stdio.h>

#define MAX_LINE	1000

int get_line(char line[], int max_line);
void copy(char to[], char from[]);

main()
{
	int len, max;
	char line[MAX_LINE], longest[MAX_LINE];

	max = 0;
	while ((len = get_line(line, MAX_LINE)) > 0) {
		printf("%d, %s", len, line);
		if (max < len) {
			max = len;
			copy(longest, line);
		}
	}
	if (max > 0) printf("%s", longest);
}

int get_line(char s[], int lim)
{
	int c, i;
	for (i=0; (c=getchar())!=EOF && c!='\n'; i++) {
		if (i<lim-2) s[i] = c;
	}
	if (c=='\n') s[i++] = c;
	s[i] = 0;
	return i;
}

void copy(char to[], char from[])
{
	int i;
	for (i = 0; to[i]=from[i]; i++);
}
