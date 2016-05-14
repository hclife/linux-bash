#include <stdio.h>
#include <string.h>

#define MAXN	1002

int N;
char vis[MAXN][MAXN];

int gcd(int x, int y)
{
	if (x%y==0) return y;
	return gcd(y,x%y);
}

int solve()
{
	register int i,j,x,y,d,c=0;
	for (i=2;i<=N;i++) {
		for (j=1;j<i;j++) {
			d=gcd(i,j);
			x=i/d;
			y=j/d;
			if (!vis[x][y]) {
				vis[x][y]=1;
				c++;
			}
		}
	}
	return 2*c+3;
}

int main(void)
{
	int i,j,t,T,Ans;
	freopen("input.txt","r",stdin);
	setbuf(stdout,NULL);
	scanf("%d",&T);
	for (t=1;t<=T;t++) {
		scanf("%d",&N);
		memset(vis,0,sizeof(vis));
		Ans=solve();
		printf("Case #%d\n%d\n",t,Ans);
	}
	return 0;
}
