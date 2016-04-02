#include <stdio.h>
#include <string.h>

int main(void)
{
	char str1[64], str2[64];
	int ans, ret, i, j;

	memset(str1, 0, sizeof(str1));
	memset(str2, 0, sizeof(str2));

	scanf("%s", str1);
	scanf("%s", str2);

	//printf("str1: %s\n", str1);
	//printf("str2: %s\n", str2);
	
	//printf("str1[%d] = %c\n", strlen(str1)-1, str1[strlen(str1)-1]);
	//printf("str1[%d] = %c\n", strlen(str1), str1[strlen(str1)]);

	i = 0;
	ret = 0;
	while (i < strlen(str1) && i < strlen(str2)) {
		ret = str1[i] - str2[i];
		//printf("ret = %d\n", ret);
		if (ret > 0)
			break;
		if (ret < 0)
			break;
		i++;
	}

	printf("%d\n", ret);



	return 0;
}

