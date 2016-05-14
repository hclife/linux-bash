#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAXN	36

int Ans;
const int N=32;
int cube[MAXN][MAXN][MAXN];

void cube_dump()
{
	int i,j,k;
	for (k=1;k<=N;k++) {
		printf("The %d level of cube:\n",k);
		for (i=1;i<=N;i++) {
			for (j=1;j<=N;j++)
				printf("%2d ",cube[k][i][j]);
			printf("\n");
		}
	}
}

void cube_compress()
{
	int i,j,k;
	//printf("cube_compress\n");
	for (k=2;k<=N;k++)
	for (i=1;i<=N;i++)
	for (j=1;j<=N;j++)
		if (cube[k][i][j])
			cube[k][i][j]=cube[k-1][i][j]+1;
}

int get_min_height(int map[MAXN][MAXN], int x1, int y1, int x2, int y2)
{
	int i,j,min=map[x1][y1];
	for (i=x1;i<=x2;i++)
		for (j=y1;j<=y2;j++)
			if (min>map[i][j])
				min=map[i][j];
	return min;
}

void cube_process(int map[MAXN][MAXN], int level)
{
	int i,j,k,x,y,m,n,maxy,minho,vol;
	//printf("cube_process level %d\n",level);
	for (i=1;i<=N;i++) {
		for (j=1;j<=N;j++) {
			if (!map[i][j]) continue;
			for (x=i;x<=N;x++) {
				if (!map[x][j]) break;
				maxy=N+1;
				for (y=j;y<maxy;y++) {
					if (!map[x][y]) {
						maxy=y;
						break;
					}
					minho=get_min_height(map,i,j,x,y);
					#if 0
					minho=map[i][j];
					for (m=i;m<=x;m++)
						for (n=j;n<=y;n++)
							if (minho>map[m][n])
								minho=map[m][n];
					#endif
					vol=(x-i+1)*(y-j+1)*minho;
					if (Ans<vol) Ans=vol;
				}
			}
		}
	}
}

int solve()
{
	int i,j,k;
	Ans=0;
	cube_compress();
	//cube_dump();
	for (k=1;k<=N;k++) {
		cube_process(cube[k],k);
	}
	return Ans;
}

int main(void)
{
	int i,j,k,t;
	srand(0);
	for (t=1;t<=10;t++) {
		for (k=1;k<=N;k++)
		for (i=1;i<=N;i++)
		for (j=1;j<=N;j++)
			cube[k][i][j]=(rand()%N==0)?0:1;
		printf("#%d %d\n",t,solve());
	}

	return 0;
}
