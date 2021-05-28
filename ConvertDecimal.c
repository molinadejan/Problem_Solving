#include <stdio.h>
#include <stdlib.h>

char* convert(int decimal, int notation);

int main(void)
{
	int decimal, notation;

	printf("10진수 입력 : ");
	scanf("%d", &decimal);

	printf("출력 진수 : ");
	scanf("%d", &notation);

	if (notation <= 36)
	{
		char *str = convert(decimal, notation);
		printf("10진수 %d는 %d진수 %s 입니다.\n", decimal, notation, str);
		free(str);
	}
	else
	{
		printf("유효하지 않은 진수범위 입니다.\n");
	}

	return 0;
}

char * convert(int decimal, int notation)
{
	int len = 0;

	for (int tmp = decimal; tmp > 0; tmp /= notation)
		++len;

	char* str = (char*)malloc((len + 1) * sizeof(char));

	str[len] = '\0';

	int idx = len - 1;

	for (int tmp = decimal; tmp > 0; tmp /= notation)
	{
		int remainder = tmp % notation;

		if (remainder < 10)
			str[idx] = '0' + remainder;
		else
			str[idx] = 'A' + remainder % 10;

		--idx;
	}

	return str;
}
