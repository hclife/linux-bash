#include <stdio.h>
#include <string.h>

char str[128];

void count(const char *s)
{
	int i, up_alpha, low_alpha, num, space, other;

	//printf("len = %d\n", strlen(s));
	up_alpha = low_alpha = num = space = other = 0;
	for (i = 0; i < strlen(s); i++) {
		if (*(s+i) >= 'a' && *(s+i) <= 'z') {
			low_alpha++;
			continue;
		}
		if (*(s+i) >= 'A' && *(s+i) <= 'Z') {
			up_alpha++;
			continue;
		}
		if (*(s+i) >= '0' && *(s+i) <= '9') {
			num++;
			continue;
		}
		if (*(s+i) == ' ') {
			space++;
			continue;
		}
		other++;
	}
	printf("There are %d upper alphabets, %d lower alphabets, %d numbers, %d spaces and %d other characters.\n",
		up_alpha, low_alpha, num, space, other);
}

int main(void)
{
	//freopen("8.8.in", "r", stdin);
	setbuf(stdout, NULL);
	memset(str, 0, sizeof(str));
	fgets(str, sizeof(str), stdin);
	//printf("%s", str);
	count(str);

	return 0;
}
