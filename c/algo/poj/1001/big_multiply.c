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

#define MAXO	(2*MAX)
LL big_number_multiply(LL A, LL B)
{
	LL V;
	int i,j,k,lena,lenb;
	int a[MAX],b[MAX],c[MAXO];
	memset(a,0,sizeof(a));
	memset(b,0,sizeof(b));
	memset(c,0,sizeof(c));
	lena=get_digits(a,A);
	lenb=get_digits(b,B);
	for (i=0;i<lena;i++)
		for (j=0;j<lenb;j++)
			c[i+j]+=(a[i]*b[j]);
	for (i=0;i<MAXO;i++) {
		c[i+1]+=c[i]/10;
		c[i]%=10;
	}
	/* might overflow */
	V=output_digits(c,MAXO);
	return V;
}