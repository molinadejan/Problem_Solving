#include <iostream>

// �־��� ���ڿ��� �ܾ� ������ ������ ������ ����ϼ���.
// �Է°� : "hello world this is xlgames"
// ��ȯ�� : "xlgames is this world hello"

// ����
// �Է� ���ڿ��� �յڿ� ������ ���ٰ� �����մϴ�.
// ��� �ܾ�� ���� �� ĭ���� ���еȴٰ� �����մϴ�.

void ReverseWords(char* output, int outputArraySize, const char* input)
{
	output = new char[outputArraySize];

	int strLen = outputArraySize - 1;
	int i = 0, wordStart = 0, outputIndexCounter = strLen - 1;

	while (i < strLen)
	{
		if (input[i] == ' ')
		{
			for (int j = i - 1; j >= wordStart; --j)
				output[outputIndexCounter--] = input[j];

			output[outputIndexCounter--] = ' ';

			wordStart = i + 1;
		}
		else if (i == strLen - 1)
		{
			for (int j = i; j >= wordStart; --j)
				output[outputIndexCounter--] = input[j];

			wordStart = i + 1;
		}

		++i;
	}

	output[strLen] = '\0';

	std::cout << output << std::endl;
}

int main(void)
{
	char* output = NULL;
	const char input[] = "He llo good kakakaka cool";
	
	ReverseWords(output, sizeof(input) / sizeof(char), input);

	return 0;
}