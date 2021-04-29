// 게임 정보학 : 게임을 개척하는 인공지능
// P21 : The game of life

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <Windows.h>

//#include <crtdbg.h>

using namespace std;

// 8방향 정의
const int DIR_X_8[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
const int DIR_Y_8[8] = {0, 1, 1, 1, 0, -1, -1, -1};

const int ALIVE = 1;
const int DEAD = 0;

// 보드 출력
void PrintBoard(int **board, const int boardSize);
// 새로운 보드 할당
void NewBoard(int ***board, const int boardSize);
// 보드 초기화
void InitBoard(int **board, const int boardSize);
// 할당된 보드 메모리 삭제
void DeleteBoard(int **board, const int boardSize);
// 보드 복사
void CopyBoard(int** dest, int **source, const int boardSize);

// 게임 한 턴 진행
void GameProgress(int **board, int **bufBoard, const int boardSize);
// 주위 8칸의 살아있는 이웃의 수 반환
int CountAliveNeighbors(int **board, const int x, const int y, const int boardSize);
// 멸종되었는지 체크
bool IsExtinction(int **board, const int boardSize);

// 인덱스 체크
bool CheckIndex(const int x, const int y, const int boardSize);

int main()
{
	//_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF || _CRTDBG_LEAK_CHECK_DF);

	srand((unsigned int)time(NULL));

	int **board, **bufBoard, boardSize;
	cin >> boardSize;

	NewBoard(&board, boardSize);
	NewBoard(&bufBoard, boardSize);

	InitBoard(board, boardSize);

	while (true)
	{
		PrintBoard(board, boardSize);

		Sleep(1000);

		if (IsExtinction(board, boardSize))
			break;

		GameProgress(board, bufBoard, boardSize);
		system("cls");
	}

	DeleteBoard(board, boardSize);
	DeleteBoard(bufBoard, boardSize);

	//_CrtDumpMemoryLeaks();

	return 0;
}

void PrintBoard(int **board, const int boardSize)
{
	for (int i = 0; i < boardSize; ++i)
	{
		for (int j = 0; j < boardSize; ++j)
			cout << (board[i][j] == ALIVE ? "■" : "□");

		cout << '\n';
	}
}

void NewBoard(int ***board, const int boardSize)
{
	*board = new int* [boardSize];

	for (int i = 0; i < boardSize; ++i)
		(*board)[i] = new int[boardSize];
}

void InitBoard(int **board, const int boardSize)
{
	for (int i = 0; i < boardSize; ++i)
		for (int j = 0; j < boardSize; ++j)
			board[i][j] = rand() % 5 > 2 ? ALIVE : DEAD;
}

void DeleteBoard(int **board, const int boardSize)
{
	for (int i = 0; i < boardSize; ++i)
		delete board[i];

	delete[] board;
}

void CopyBoard(int** dest, int** source, const int boardSize)
{
	for (int i = 0; i < boardSize; ++i)
		for (int j = 0; j < boardSize; ++j)
			dest[i][j] = source[i][j];
}

void GameProgress(int** board, int** bufBoard, const int boardSize)
{
	for (int i = 0; i < boardSize; ++i)
	{
		for (int j = 0; j < boardSize; ++j)
		{
			int aliveCnt = CountAliveNeighbors(board, i, j, boardSize);
			
			if (board[i][j] == ALIVE)
			{
				if (aliveCnt == 2 || aliveCnt == 3)
					bufBoard[i][j] = ALIVE;
				else
					bufBoard[i][j] = DEAD;
			}
			else // board[i][j] == DEAD
			{
				if (aliveCnt == 2 || aliveCnt == 3)
					bufBoard[i][j] = ALIVE;
			}
		}
	}

	CopyBoard(board, bufBoard, boardSize);
}

int CountAliveNeighbors(int** board, const int x, const int y, const int boardSize)
{
	int ret = 0;

	for (int i = 0; i < 8; ++i)
	{
		int nx = x + DIR_X_8[i];
		int ny = y + DIR_Y_8[i];

		if (CheckIndex(nx, ny, boardSize) && board[nx][ny] == ALIVE)
			++ret;
	}

	return ret;
}

bool IsExtinction(int** board, const int boardSize)
{
	for (int i = 0; i < boardSize; ++i)
		for (int j = 0; j < boardSize; ++j)
			if (board[i][j] == ALIVE)
				return false;

	return true;
}

bool CheckIndex(const int x, const int y, const int boardSize)
{
	if (x < 0 || y < 0 || x >= boardSize || y >= boardSize)
		return false;

	return true;
}