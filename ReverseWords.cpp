#include <iostream>

// 주어진 문자열을 단어 단위로 순서를 뒤집어 출력하세요.
// 입력값 : "hello world this is xlgames"
// 반환값 : "xlgames is this world hello"

// 조건
// 입력 문자열은 앞뒤에 공백이 없다고 가정합니다.
// 모든 단어는 공백 한 칸으로 구분된다고 가정합니다.

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