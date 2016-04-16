/* detab */

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

void detab(char s[])
{
	char t[MAX]={0};
	int i,j,j1,x;
	for (i=j=0;s[i];i++) {
		if (s[i]!='\t') {
			t[j++]=s[i];
			continue;
		}
		j1=j;
		for (x=j1;x<(j1/TAB+1)*TAB;x++)
			t[j++]=' ';
	}
	t[j]=0;
	for (x=0;x<=j;x++) s[x]=t[x];
}

main()
{
	int len;
	char line[MAX]={0};
	freopen("1-20.in","r",stdin);
	freopen("1-20.out","w",stdout);
	while (len=get(line)) {
		detab(line);
		printf("%s",line);
	}
}
