//  ������ �迭 ���� ä���
//  https://codeup.kr/problem.php?id=1477
//  n : 3, m : 4
//  1   2   5   7
//  3   5   8  10
//  6   9  11  12

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

	for (int i = 1; i <= n + m; ++i)
	{
		for (int j = 0; j < i; ++j)
		{
			if (i - j - 1 >= m || j >= n)
				continue;

			arr[j][i - j - 1] = num++;
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