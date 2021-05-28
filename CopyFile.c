#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <Windows.h>
#include <string.h>
#include <stdlib.h>

void FileOpen(FILE **f, char *path, char *mode);
void FileClose(FILE *f);

int main(void)
{
	FILE *fs, *fd;
	char sourceName[100], destName[100];
	int fileSize, progress = 0, res;

	printf("원본 파일 입력 : ");
	scanf("%s", sourceName);

	printf("대상 파일 입력 : ");
	scanf("%s", destName);

	FileOpen(&fs, sourceName, "rb");
	FileOpen(&fd, destName, "wb");

	fseek(fs, 0, SEEK_END);
	fileSize = ftell(fs);
	fseek(fs, 0, SEEK_SET);

	int cur = 0;

	while (1)
	{
		system("cls");

		int readCnt;

		readCnt = fread(&res, 1, 4, fs);
		cur += readCnt;
		printf("현재 진행중 : %.2lf%% (%d / %d)", cur / (double)fileSize * 100.0, cur, fileSize);
		fwrite(&res, 1, readCnt, fd);

		if (readCnt < 4)
			break;
	}

	printf("\n\n파일 복사 완료!!\n");

	FileClose(fs);
	FileClose(fd);

	return 0;
}

void FileOpen(FILE **f, char *path, char *mode)
{
	if (((*f) = fopen(path, mode)) == NULL)
	{
		printf("File %s open error\n", path);
		exit(1);
	}
}

void FileClose(FILE *f)
{
	if(f != NULL)
		fclose(f);
}
