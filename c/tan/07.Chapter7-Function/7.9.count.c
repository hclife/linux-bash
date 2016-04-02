#include <stdio.h>
#include <string.h>

void counting(char s[])
{
	int i, alpha, num, space, other;

	//puts(s);
	alpha = num = space = other = 0;
	for (i = 0; i < strlen(s); i++) {
		if (s[i] >= 'a' && s[i] <= 'z') {
			alpha++;
			continue;
		}

		if (s[i] >= 'A' && s[i] <= 'Z') {
			alpha++;
			continue;
		}

		if (s[i] >= '0' && s[i] <= '9') {
			num++;
			continue;
		}

		if (s[i] == ' ') {
			space++;
			continue;
		}

		other++;
	}

	printf("There are %d alphabets, %d numbers, %d spaces and %d other characters.\n", alpha, num, space, other);

}

int main(void)
{
	char str[128];

	memset(str, 0, sizeof(str));
	gets(str);
	counting(str);

	return 0;
}
