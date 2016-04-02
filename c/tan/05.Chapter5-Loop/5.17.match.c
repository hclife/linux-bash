#include <stdio.h>

int main(void)
{
	/* x1 - y1, x2 - y2, x3 - y3 */
	char x1 = 'A';
	char x2 = 'B';
	char x3 = 'C';
	char y1, y2, y3;

	y1 = 'Y';
	if (y1 == 'Y') {
		y2 = 'X';
		y3 = 'Z';
		if (y3 != 'X' && y3 != 'Z')
			printf("%c-%c, %c-%c, %c-%c\n",
				x1, y1, x2, y2, x3, y3);

		y2 = 'Z';
		y3 = 'X';
		if (y3 != 'X' && y3 != 'Z')
			printf("%c-%c, %c-%c, %c-%c\n",
				x1, y1, x2, y2, x3, y3);
	}

	y1 = 'Z';
	if (y1 == 'Z') {
		y2 = 'X';
		y3 = 'Y';
		if (y3 != 'X' && y3 != 'Z')
			printf("%c-%c, %c-%c, %c-%c\n",
				x1, y1, x2, y2, x3, y3);

		y2 = 'Y';
		y3 = 'X';
		if (y3 != 'X' && y3 != 'Z')
			printf("%c-%c, %c-%c, %c-%c\n",
				x1, y1, x2, y2, x3, y3);
	}

	return 0;
}
