#include <iostream>

// �� �� ���� X�� ������ �������� ���� ���ڰ� �����ؼ� 2�� ������ int �迭�� �ִ�.
// �ð����⵵�� ����Ͽ� �� ���� ������ ���� X�� ã�ƶ�.

// �Է°� : [1, 1, 2, 2, 8, 8, 3, 5, 5, 0, 0]
// ��ȯ�� : 3

int FindSingleNumber(int* numbers, int arraySize)
{
	int i;

	for (i = 1; i < arraySize; i += 2)
		if (numbers[i] != numbers[i - 1])
			return numbers[i - 1];

	return numbers[i - 1];
}

int main(void)
{
	int arr[] = {2, 1, 2, 2, 8, 8, 3, 3, 0, 0};

	std::cout << FindSingleNumber(arr, sizeof(arr) / sizeof(arr[0])) << std::endl;

	return 0;
}