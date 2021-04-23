//  ������ �迭 ���� ä���
//  n : 3, m : 4
//  1   3   6   9
//  2   5   8  11
//  4   7  10  12

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
			if (i - j - 1 >= n || j >= m) 
				continue;

			arr[i - j - 1][j] = num++;
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