#include <iostream>

// ���簢�� �̹����� ��Ÿ���� ������ 2���� �迭�� �־�����.
// �̹����� ũ��� ������ ���� �ʴ�.
// ������ �޸𸮸� ���� ����ؼ� �̹����� �ð�������� 90�� ȸ���Ͽ���

// �Է°� : 
// 1, 2, 3,
// 4, 5, 6,
// 7, 8, 9

// ����� �� :
// 7, 4, 1,
// 8, 5, 2,
// 9, 6, 3

void RotateRectangle(int* image, int width)
{
	for (int n = 0; n < width / 2; ++n)
	{
		for (int m = n; m < width - n - 1; ++m)
		{
			int tmp = image[m * width + n];
			image[m * width + n] = image[(width - n - 1) * width + m];
			image[(width - n - 1) * width + m] = image[(width - m - 1) * width + width - n - 1];
			image[(width - m - 1) * width + width - n - 1] = image[n * width + width - m - 1];
			image[n * width + width - m - 1] = tmp;
		}
	}
}

void PrintRectangle(int* image, int width)
{
	int indexCount = 0;

	for (int i = 0; i < width; ++i)
	{
		for (int j = 0; j < width; ++j)
			std::cout << image[indexCount++] << " ";
		std::cout << "\n";
	}

	std::cout << "\n";
}

int main(void)
{
	const int width = 4;

	int image[width][width];

	for (int i = 0; i < width; ++i)
		for (int j = 0; j < width; ++j)
			image[i][j] = i * width + j;

	PrintRectangle(*image, width);

	RotateRectangle(*image, width);

	PrintRectangle(*image, width);

	return 0;
}