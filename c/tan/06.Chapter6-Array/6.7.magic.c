#include <stdio.h>
#include <string.h>

#define MAX 1024

int map[MAX][MAX];
int data[MAX * MAX];
int N;
int sum;
int numb;

void dump(void)
{
	int i, j;

	printf("dump map:\n");
	for (i = 1; i <= N; i++) {
		for (j = 1; j <= N; j++)
			printf("%2d ", map[i][j]);
		printf("\n");
	}
}

int visit(int x, int y)
{
	int i, j, k;
	int ret = -3;
	int row, col, acc, left;
	int dig1, dign;

#ifdef DEBUG
	printf("visit: (%d, %d), sum: %d\n", x, y, sum);
	dump();
#endif

	if (x < 1 || y < 1) {
		//printf("(%d, %d) too low\n", x, y);
		return -1;
	}

	if (x > N || y > N) {
		//printf("(%d, %d) too high\n", x, y);
		return 1;
	}

	/* check column & diagonal */
	if (x == N) {

		/* column value */
		acc = 0;
		for (i = 1; i <= N-1; i++)
			acc += map[i][y];
		col = sum - acc;
		if (col <= 0)
			return -1;
		if (col > N * N)
			return -1;
#ifdef DEBUG
		printf("x: col = %d\n", col);
		printf("x: data[col] = %d\n", data[col]);
#endif
		if (data[col])
			return -1;

		if (y == 1) {
			acc = 0;
			for (i = 1; i <= N-1; i++)
				acc += map[i][N-i+1];
			dig1 = sum - acc;
#ifdef DEBUG
			printf("dig1 = %d\n", dig1);
			printf("data[dig1] = %d\n", data[dig1]);
#endif
			if (dig1 <= 0)
				return -1;
			if (dig1 > N * N)
				return -1;
			if (col != dig1)
				return -1;
			if (data[dig1])
				return -1;

			data[dig1] = 1;
			map[x][y] = dig1;
			ret = visit(x, y+1);
			if (ret <= 0) {
				data[dig1] = 0;
				map[x][y] = 0;
			}
			return ret;
		}

		if (y == N) {
			acc = 0;
			for (i = 1; i <= N-1; i++)
				acc += map[i][i];
			dign = sum - acc;
#ifdef DEBUG
			printf("dign = %d\n", dign);
			printf("data[dign] = %d\n", data[dign]);
#endif
			if (dign <= 0)
				return -1;
			if (dign > N * N)
				return -1;

			acc = 0;
			for (i = 1; i <= N-1; i++)
				acc += map[x][i];
			row = sum - acc;
#ifdef DEBUG
			printf("row = %d\n", row);
			printf("data[row] = %d\n", data[row]);
#endif
			if (row <= 0)
				return -1;
			if (row > N * N)
				return -1;
			
			/* compare row, col, dign */
			if (row != col)
				return -1;
			if (row != dign)
				return -1;
			if (col != dign)
				return -1;
			if (data[dign])
				return -1;

			data[dign] = 1;
			map[x][y] = dign;
			return visit(x+1, y+1);
		}

		data[col] = 1;
		map[x][y] = col;
		ret = visit(x, y+1);
		if (ret <= 0) {
			data[col] = 0;
			map[x][y] = 0;
		}
		return ret;

	}

	/* check row and turn back */
	if (y == N) {

		acc = 0;
		for (i = 1; i <= N-1; i++)
			acc += map[x][i];
		left = sum - acc;
#ifdef DEBUG
		printf("left = %d\n", left);
		printf("data[left] = %d\n", data[left]);
#endif
		if (left <= 0)
			return -1;
		if (left > N * N)
			return -1;

		if (data[left])
			return -1;

		data[left] = 1;
		map[x][y] = left;
		ret = visit(x+1, 1);
		if (ret <= 0) {
			data[left] = 0;
			map[x][y] = 0;
		}
		return ret;
	}

	/* check the current status */
	acc = 0;
	for (i = 1; i <= y-1; i++)
		acc += map[x][i];
	row = acc;
	if (row > sum)
		return -1;

	acc = 0;
	for (i = 1; i <= x-1; i++)
		acc += map[i][y];
	col = acc;
	if (col > sum)
		return -1;

	acc = 0;
	for (i = 1; i <= x-1; i++)
		acc += map[i][N-i+1];
	dig1 = acc;
	if (dig1 > sum)
		return -1;

	acc = 0;
	for (i = 1; i <= x-1; i++)
		acc += map[i][i];
	dign = acc;
	if (dign > sum)
		return -1;

	for (i = 1; i <= N*N; i++) {
		if (data[i])
			continue;
		map[x][y] = i;
		data[i] = 1;
		ret = visit(x, y+1);
		if (ret <= 0) {
			data[i] = 0;
			map[x][y] = 0;
		} else
			break;
	}

	return ret;
}

int main(void)
{
	int i, j, k;
	int ret;
	
	scanf("%d", &N);
	//N = 3;
	numb = N * N;
	for (i = 1; i <= N; i++)
		for (j = 1; j <= N; j++)
			map[i][j] = 0;
	for (i = 1; i <= numb; i++)
		data[i] = 0;

	if (N == 1) {
		printf("1\n");
		return 0;
	}

	sum = (1 + numb) * N / 2;
	printf("main: sum = %d\n", sum);
	ret = visit(1, 1);
	if (ret < 0) {
		printf("-1\n");
		return 0;
	}

#if 1
	printf("main: ret = %d\n", ret);
	for (i = 1; i <= N; i++) {
		for (j = 1; j <= N; j++)
			printf("%2d ", map[i][j]);
		printf("\n");
	}
#endif


	return 0;
}





