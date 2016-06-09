#include <stdio.h>

#define MAX_LINE	1000

int max;
char line[MAX_LINE], longest[MAX_LINE];

int get_line(void);
void copy(void);

main()
{
	int len;

	max = 0;
	while ((len=get_line())>0) {
		if (max < len) {
			max = len;
			copy();
		}
	}
	if (max>0) printf("%s", longest);
}

int get_line(void)
{
	int c, i;
	for (i = 0; i < MAX_LINE-1 && (c=getchar())!=EOF &&
		c != '\n'; i++)
		line[i] = c;
	if (c == '\n') line[i++] = c;
	line[i] = '\0';

	return i;
}

void copy(void)
{
	int i;
	for (i = 0; longest[i] = line[i]; i++);
}
