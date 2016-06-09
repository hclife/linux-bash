#include <stdio.h>

#define MAX_LINE	1000

int get_line(char line[], int maxline);
int remove_line(char s[]);

main()
{
	char line[MAX_LINE];
	freopen("1-18.in", "r", stdin);
	while (get_line(line, MAX_LINE) > 0)
		if (remove_line(line) > 0) printf("%s", line);
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

int remove_line(char s[])
{
	int i = 0;
	while (s[i]!='\n') ++i;
	--i;
	while (i >= 0 && (s[i]==' ' || s[i]=='\t')) --i;
	if (i >= 0) {
		s[++i]='\n';
		s[++i]=0;
	}
	return i;
}
