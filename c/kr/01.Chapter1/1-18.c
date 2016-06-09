#include <stdio.h>

#define MAX	1000

int get(char *s, int limit)
{
	int c,i,j,ok=0;
	for (i=0;i<limit-1 && (c=getchar())!=EOF &&
	     c!='\n'; i++) {
		s[i]=c;
		if (c!=' ') ok=1;
	}
	//printf("ok=%d,i=%d\n",ok,i);
	if (c==EOF) return -2;
	if (!ok&&i) return -1;
	for (j=i-1;j>=0;j--)
		if (s[j]!=' '&&s[j]!='\t') break;
	//printf("j=%d\n",j);
	if (j<0) return -1;
	if (c=='\n') s[++j]=c;
	s[++j]=0;
	return j;
}

main()
{
	int len;
	char line[MAX];
	freopen("1-18.in", "r", stdin);
	while (len=get(line, MAX)) {
		if (len==-1) continue;
		if (len<-1) break;
		printf("%s", line);
	}
}

