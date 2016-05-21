#include <stdio.h>
#include <string.h>

#define MAX	1024
#define MAXO	2048
#define LL	long long


int N;
char buf[16];
int LenA,LenB,LenO,total_floats;
int A[MAX],B[MAX],O[MAX],out[MAX];

void dump(int a[], int n)
{
	int i;
	printf("dump: ");
	for (i=0;i<n;i++) printf("%d",a[i]);
	printf("\n");
}

void dump_ans()
{
	int i;
	for (i=LenO;i>=0;i--) {
		if (O[i]=='.') printf(".");
		else printf("%d",O[i]);
	}
	printf("\n");
}

void insert_points()
{
	int i;
	int x=total_floats;
	if (x>0) {
		for (i=LenO;i>=x;i--)
			O[i+1]=O[i];
		O[x]='.';
	}

	for (i=LenO+1;i>0;i--) {
		if (O[i]) break;
		if (O[i]=='.') break;
	}
	LenO=i;
}

int get_digits(int s[], LL n)
{
	int i,d;
	i=0;
	while (n) {
		d=n%10;
		s[i++]=d;
		n/=10;
	}
	return i;
}

LL output_digits(int s[], int len)
{
	LL v=0;
	int i,j;
	for (j=len-1;!s[j];j--);
	for (i=j;i>=0;i--)
		v=v*10+s[i];
	return v;
}

LL big_number_multiply(LL A, LL B)
{
	LL V;
	int i,j,k,lena,lenb,lenc;
	int a[MAX],b[MAX],c[MAXO];
	memset(a,0,sizeof(a));
	memset(b,0,sizeof(b));
	memset(c,0,sizeof(c));
	lena=get_digits(a,A);
	lenb=get_digits(b,B);
	if (lena>lenb) lenc=lena;
	else lenc=lenb;
	lenc=lenc*2+7;
	dump(a,lena);
	dump(b,lenb);
	for (i=0;i<lena;i++)
		for (j=0;j<lenb;j++)
			c[i+j]+=(a[i]*b[j]);
	for (i=0;i<lenc;i++) {
		c[i+1]+=c[i]/10;
		c[i]%=10;
	}
	/* might overflow */
	V=output_digits(c,lenc);
	return V;
}

void input_digits()
{
	register int i,j,k,point,floats;
	size_t len=strlen(buf);
	point=floats=j=0;
	for (k=len-1;k>=0;k--)
		if (buf[k]!='0') break;
	for (i=k;i>=0;i--) {
		if (buf[i]=='.') {
			point=1;
			continue;
		}
		if (!point) floats++;
		A[j++]=buf[i]-'0';
	}
	LenA=j;
	total_floats=floats*N;
	//printf("floats=%d,total_floats=%d\n",floats,total_floats);
	//dump(A,j);
}

void copy()
{
	int i;
	for (i=0;i<=LenA;i++) O[i]=A[i];
	LenO=LenA;
	return;
}

int multiply(int X[], int n)
{
	int i,j,len_out=LenO+n;
	memset(out,0,sizeof(out));
	for (i=0;i<LenO;i++)
		for (j=0;j<n;j++)
			out[i+j]+=(O[i]*X[j]);
	for (i=0;i<len_out;i++) {
		out[i+1]+=out[i]/10;
		out[i]%=10;
	}
	memcpy(O,out,sizeof(out));
	return len_out;
}

void power(int n)
{
	if (n<=1) {
		copy();
		return;
	}

	if (n%2==0) {
		power(n/2);
		LenO=multiply(O,LenO);
		return;
	}

	power(n-1);
	LenO=multiply(A,LenA);
}

void solve()
{
	//printf("solve: N=%2d,buf:%s\n",N,buf);
	LenA=LenB=LenO=0;
	memset(A,0,sizeof(A));
	memset(B,0,sizeof(B));
	memset(O,0,sizeof(O));
	input_digits();
	power(N);
	//dump(O,LenO);
	insert_points();
	dump_ans();
}

int main(void)
{
#if 1
	int i,j;
	//freopen("input.txt","r",stdin);
	setbuf(stdout,NULL);
	while (scanf("%s%d",buf,&N)==2) {
		solve();
	}
#else
	LL x,y,ans;
	while (1) {
		scanf("%lld %lld",&x,&y);
		ans=big_number_multiply(x,y);
		printf("x=%lld,y=%lld,ans=%lld\n",x,y,ans);
	}
#endif

	return 0;
}
