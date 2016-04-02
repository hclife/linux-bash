#include <stdio.h>
#include <string.h>

int M, N;
int map[128][128];

int main(void)
{
	int T;
	int i, j;
	int max, min, row_idx, col_idx;
	int flag;

	freopen("matrix.txt", "r", stdin);
	setbuf(stdout, NULL);
	scanf("%d", &T);
	while (T--) {
		scanf("%d %d", &M, &N);

		memset(map, 0, sizeof(map));
		for (i = 1; i <= M; i++)
			for (j = 1; j <= N; j++)
				scanf("%d", &map[i][j]);

#if 1
		printf("M = %d, N = %d\n", M, N);
		for (i = 1; i <= M; i++) {
			for (j = 1; j <= N; j++)
				printf("%2d ", map[i][j]);
			printf("\n");
		}
#endif

		flag = 0;
		for (i = 1; i <= M; i++) {
			max = map[i][1];
			col_idx = 1;
			for (j = 2; j <= N; j++) {
				if (max < map[i][j]) {
					max = map[i][j];
					col_idx = j;
				}
			}
			//printf("max = %d, col_idx = %d\n", max, col_idx);

			min = map[1][col_idx];
			row_idx = 1;
			for (j = 2; j <= M; j++) {
				if (min > map[j][col_idx]) {
					min = map[j][col_idx];
					row_idx = j;
				}
			}
			//printf("min = %d, row_idx = %d\n", min, row_idx);
			//printf("\n");
			if (row_idx == i) {
				flag = 1;
				printf("Point: map[%d][%d] = %d\n", row_idx, col_idx, map[row_idx][col_idx]);
				break;
			}
		}
		if (!flag)
			printf("No point\n");

	}

	return 0;
}
