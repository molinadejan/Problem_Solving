#define _CRT_SECURE_NO_WARNINGS

/*

Output : 
1   2   3   4   5
16  17  18  19   6
15  24  25  20   7
14  23  22  21   8
13  12  11  10   9

*/

#include <stdio.h>

#define N 5

void PrintArray(int* arr, int row, int col);
int CheckNext(int* arr, int x, int y, const int limit);

int main(void)
{
	int arr[N][N] = { 0, };

	int next_x[4] = { 0, 1, 0, -1 };
	int next_y[4] = { 1, 0, -1, 0 };

	int direction = 0;

	int xPos = 0, yPos = 0, curNum = 1;

	for (int i = 0; i < N * N; ++i)
	{
		arr[xPos][yPos] = curNum++;

		if (!CheckNext((int*)arr, xPos + next_x[direction], yPos + next_y[direction], N))
		{
			++direction;
			direction %= 4;
		}

		xPos += next_x[direction];
		yPos += next_y[direction];
	}

	PrintArray((int*)arr, N, N);

	return 0;
}

void PrintArray(int* arr, int row, int col)
{
	for (int i = 0; i < row; ++i)
	{
		for (int j = 0; j < col; ++j)
			printf("%3d ", arr[i * col + j]);
		putchar('\n');
	}

	putchar('\n');
}

int CheckNext(int* arr, int x, int y, const int limit)
{
	if (x < 0 || y < 0 || x >= limit || y >= limit || arr[x * limit + y])
		return 0;
	return 1;
}
