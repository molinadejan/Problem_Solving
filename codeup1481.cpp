//  이차원 배열 빗금 채우기 3-6
//  https://codeup.kr/problem.php?id=1481
//  n : 3, m : 4
// 12  11   9   6
// 10   8   5   3
//  7   4   2   1

#include <iostream>

using namespace std;

int main(void)
{
	int n, m;
	cin >> n >> m;

	// n x m 배열 동적 할당
	int** arr = new int* [n];
	for (int i = 0; i < n; ++i)
		arr[i] = new int[m];

	int num = 1;

	for (int i = 1; i < n + m; ++i)
	{
		for (int j = 0; j < i; ++j)
		{
			if (n - j - 1 < 0 || m + j - i < 0)
				continue;

			arr[n - j - 1][m + j - i] = num++;
		}
	}

	// 배열 출력
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
			cout << arr[i][j] << " ";
		cout << endl;
	}

	// 메모리 해제
	for (int i = 0; i < n; ++i)
		delete arr[i];
	delete[] arr;

	return 0;
}