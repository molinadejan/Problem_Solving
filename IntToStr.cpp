#include <iostream>

// int�� �������� �Է¹޾� ���ڿ��� ��ȯ�ϴ� �Լ��� ���弼��.
// �Է°� : 1819
// ��ȯ�� : "1819"

void IntToStr(char* output, int outputArraySize, int input)
{
	output = new char[outputArraySize];
	int strLen = outputArraySize - 1;
	output[strLen] = '\0';

	for (int i = strLen - 1; i >= 0; --i)
	{
		output[i] = (input % 10) + '0';
		input /= 10;
	}

	std::cout << output << std::endl;
}

int main(void)
{
	char* output = NULL;
	int input = 1819;

	IntToStr(output, 5, input);

	return 0;
}