#include <iostream>

// 단 한 숫자 X를 제외한 나머지는 같은 숫자가 연속해서 2번 나오는 int 배열이 있다.
// 시간복잡도를 고려하여 한 번만 나오는 숫자 X를 찾아라.

// 입력값 : [1, 1, 2, 2, 8, 8, 3, 5, 5, 0, 0]
// 반환값 : 3

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