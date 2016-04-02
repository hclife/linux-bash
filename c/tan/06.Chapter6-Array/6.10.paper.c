#include <stdio.h>
#include <string.h>

char map[6][100];

int main(void)
{
	int i, j, p;
	char ch;
	int Word, word, num, space, other;

	freopen("paper.txt", "r", stdin);
	setbuf(stdout, NULL);
	memset(map, 0, sizeof(map));
	for (i = 1; i <= 3; i++) {
		for (j = 0; j < 80; j++) {
			ch = getchar();
			//printf("%c\n", ch);
			if (ch == '\n')
				break;
			map[i][j] = ch;
		}
	}	

#if 0
	printf("The char map is:\n");
	for (i = 1; i <= 3; i++) {
		printf("strlen(map[%d]) = %d\n", i, strlen(map[i]));
		printf("%s\n", map[i]);
	}
#endif

	Word = word = num = space = other = 0;
	for (i = 1; i <= 3; i++) {
		for (j = 0; j < strlen(map[i]); j++) {
			if (map[i][j] >= 'A' && map[i][j] <= 'Z') {
				Word++;
				continue;
			}

			if (map[i][j] >= 'a' && map[i][j] <= 'z') {
				word++;
				continue;
			}

			if (map[i][j] >= '0' && map[i][j] <= '9') {
				num++;
				continue;
			}

			if (map[i][j] == ' ') {
				space++;
				continue;
			}

			other++;
		}
	}

	printf("%d %d %d %d %d\n", Word, word, num, space, other);

	return 0;
}
