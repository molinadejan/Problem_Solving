//  ������ �迭 ���� ä��� 3-5
//  https://codeup.kr/problem.php?id=1480
//  n : 3, m : 4
// 12  10   7   4
// 11   8   5   2
//  9   6   3   1

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
		for (int j = i - 1; j >= 0; --j)
		{
			if (n - j - 1 < 0 || m + j - i < 0)
				continue;

			arr[n - j - 1][m + j - i] = num++;
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