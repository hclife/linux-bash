#include <stdio.h>
#include <string.h>

char Alpha[30], alpha[30];
char str[30], out[30];

int main(void)
{
	int i, j;
	char ch;
	int p;

	//scanf("%s", str);
	memset(str, 0, sizeof(str));
	p = 0;
	while (1) {
		ch = getchar();
		//printf("ch = %c\n", ch);
		if (ch == '\n')
			break;
		str[p++] = ch;
	}

	//return 0;

	memset(Alpha, 0, sizeof(Alpha));
	memset(alpha, 0, sizeof(alpha));
	memset(out, 0, sizeof(out));

	//printf("%s\n", str);

	for (i = 1; i <= 26; i++)
		Alpha[i] = 'A'+i-1;
	for (i = 1; i <= 26; i++)
		alpha[i] = 'a'+i-1;

#if 0
	printf("Alpha: ");
	for (i = 1; i <= 26; i++)
		printf("%c", Alpha[i]);
	printf("\n");

	printf("alpha: ");
	for (i = 1; i <= 26; i++)
		printf("%c", alpha[i]);
	printf("\n");
#endif

	for (i = 0; i < strlen(str); i++) {
		if (str[i] >= 'A' && str[i] <= 'Z') {
			out[i] = Alpha[26-(str[i]-'A'+1)+1];
			continue;
		}

		if (str[i] >= 'a' && str[i] <= 'z') {
			out[i] = alpha[26-(str[i]-'a'+1)+1];
			continue;
		}

		out[i] = str[i];
	}

	printf("%s\n", str);
	printf("%s\n", out);



	return 0;
}
