#include <stdio.h>
#include <string.h>

int N;
char employee[16][64];
int number[16];

void input(void)
{
	int i, j, k;

	//printf("input enter\n");
	scanf("%d", &N);
	for (i = 1; i <= N; i++) {
		scanf("%s", employee[i]);
		scanf("%d", &number[i]);
	}
}

void swap_int(int *a, int *b)
{
	int t;

	t = *a;
	*a = *b;
	*b = t;
}

void swap_str(char *s1, char *s2)
{
	char t[64];

	memset(t, 0, sizeof(t));
	strcpy(t, s1);
	strcpy(s1, s2);
	strcpy(s2, t);
}

void sort(void)
{
	int i, j;

	for (i = 1; i < N; i++) {
		for (j = 1; j <= N-i; j++) {
			if (number[j] > number[j+1]) {
				swap_int(&number[j], &number[j+1]);
				swap_str(employee[j], employee[j+1]);
			}
		}
	}
}

int bsearch(int s[], int l, int h, int key)
{
	int m = (l + h) / 2;

	if (l > h)
		return -1;

	if (key == s[m])
		return m;

	if (key < s[m])
		return bsearch(s, l, m-1, key);

	return bsearch(s, m+1, h, key);
}

char *find(int n)
{
	int i, j;
	int ret;

	//printf("find: %d\n", n);
	ret = bsearch(number, 1, N, n);
	if (ret < 0)
		return NULL;

	return employee[ret];
}

int main(void)
{
	int i, j;
	int num;
	char *p;

	freopen("employee.txt", "r", stdin);
	setbuf(stdout, NULL);
	input();
	sort();

#if 1
	printf("There are %d employee of company.\n", N);
	for (i = 1; i <= N; i++)
		printf("%2d: %s\n", number[i], employee[i]);
#endif


	printf("Please input the employ number:\n");
	scanf("%d", &num);
	p = find(num);
	if (!p) {
		printf("cannot find this man\n");
		return 0;
	}
	printf("This man is %s\n", p);

	return 0;
}
