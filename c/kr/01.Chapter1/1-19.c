#include <stdio.h>

#define MAX	1024

void reverse(char *s, int n)
{
	int i,j,t;
	for (i=0,j=n-1;i<j;i++,j--) {
		t=s[i];s[i]=s[j];s[j]=t;
	}
}

int get(char *s)
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
	while (len=get(line)) {
		reverse(line, len-1);
		printf("%s", line);
	}
}
