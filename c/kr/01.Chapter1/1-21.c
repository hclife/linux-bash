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

void entab(char s[])
{
	char t[MAX]={0};
	int i,i1,j,k,x,y,tab,sp;
	//printf("S:\n%s",s);
	for (i=j=0;s[i];) {
		if (s[i]!=' ') {
			t[j++]=s[i++];
			continue;
		}
		y=(i/8+1)*8-i;
		i1=i;
		for (x=0;s[i]==' ';x++,i++);
		//printf("i1=%d,y=%d,x=%d,i=%d\n",i1,y,x,i);
		if (x<y) {
			for (k=1;k<=x;k++) t[j++]=' ';
			continue;
		}
		tab=(x-y)/8+1;
		sp=(x-y)%8;
		for (k=1;k<=tab;k++) t[j++]='\t';
		for (k=1;k<=sp;k++) t[j++]=' ';
	}
	t[j]=0;
	//printf("T:\n%s",t);
	for (x=0;x<=j;x++) s[x]=t[x];
}

main()
{
	int len;
	char line[MAX]={0};
	freopen("1-21.in","r",stdin);
	freopen("1-21.out","w",stdout);
	while (len=get(line)) {
		entab(line);
		printf("%s",line);
	}
}
