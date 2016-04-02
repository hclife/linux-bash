#include <stdio.h>

#if 0
void copy_string(const char from[], char to[])
{
	int i = 0;

	while (from[i]) {
		to[i] = from[i];
		i++;
	}
	to[i] = '\0';
}
#endif

void copy_string(const char *from, char *to)
{
	while (*to++ = *from++);
}

int main(void)
{
	char a[] = "I am a teacher";
	char b[] = "You are a student";

	printf("string a = %s\n", a);
	printf("string b = %s\n", b);

	printf("copy string a to string b:\n");
	copy_string(a, b);

	printf("string a = %s\n", a);
	printf("string b = %s\n", b);

	return 0;
}

