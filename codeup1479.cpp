//  ������ �迭 ���� ä��� 3-4
//  https://codeup.kr/problem.php?id=1479
//  n : 3, m : 4
//  9   6   3   1
// 11   8   5   2
// 12  10   7   4

#include <iostream>

using namespace std;

int main(void)
{
	int n, m;
	cin >> n >> m;

	// n x m �迭 ���� �Ҵ�
	int** arr = new int* [n];
	for (int i = 0; i < n; ++i)
		arr[i] = new int[m];

	int num = 1;

	for (int i = 1; i < n + m; ++i)
	{
		for (int j = 0; j < i; ++j)
		{
			if (m - j - 1 < 0 || m - j - 1 >= m || i - j - 1 >= n)
				continue;

			arr[i - j - 1][m - j - 1] = num++;
		}
	}

	// �迭 ���
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
			cout << arr[i][j] << " ";
		cout << endl;
	}

	// �޸� ����
	for (int i = 0; i < n; ++i)
		delete arr[i];
	delete[] arr;

	return 0;
}