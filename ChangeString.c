#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>

// I am a boy hahaha.
// I am a girl hahaha.
// 단어 치환

char *ChangeString(char* string, char* find, char* change);

int main(void)
{
	char szBuf[32] = { "I am a boy hahaha." };
	printf("%s\n", ChangeString(szBuf, "boy", "girl"));

	return 0;
}

char *ChangeString(char* string, char* find, char* change)
{
	char *target = strstr(string, find);

	if (target != NULL)
	{
		char tmpBuffer[256];

		strcpy(tmpBuffer, target + strlen(find));
		strcpy(target, change);
		strcat(target, tmpBuffer);
	}

	return string;
}
