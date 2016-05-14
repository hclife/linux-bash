#include <stdio.h>
#include <string.h>

#define MAX	1000
#define MAXN	1004

int N,dp[MAXN];
char vis[MAXN][MAXN];

void dump_dp()
{
	int i;
	printf("The dp ans: ");
	for (i=1;i<=10;i++)
		printf("%d ",dp[i]);
	printf("\n");
}

int gcd(int x, int y)
{
	if (x%y==0) return y;
	return gcd(y,x%y);
}

void solve()
{
	register int c,d,n,i,j,x,y;
	memset(dp,0,sizeof(dp));
	memset(vis,0,sizeof(vis));
	dp[1]=3;
	vis[0][1]=vis[1][0]=vis[1][1]=1;
	for (n=2;n<=MAX;n++) {
		c=0;
		for (i=1;i<n;i++) {
			d=gcd(i,n);
			x=i/d;
			y=n/d;
			if (!vis[x][y]) {
				vis[x][y]=1;
				c++;
			}
		}
		for (j=1;j<n;j++) {
			d=gcd(n,j);
			x=n/d;
			y=j/d;
			if (!vis[x][y]) {
				vis[x][y]=1;
				c++;
			}
		}
		dp[n]=dp[n-1]+c;
	}
}

int main(void)
{
	int t,T;
	freopen("input.txt","r",stdin);
	setbuf(stdout,NULL);
	scanf("%d",&T);
	solve();
	for (t=1;t<=T;t++) {
		scanf("%d",&N);
		printf("Case #%d\n%d\n",t,dp[N]);
	}
	return 0;
}
