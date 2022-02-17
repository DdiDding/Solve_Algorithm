#include <stdio.h>
#include <string.h>

#define CHECK_INIT memset(bBoard, false, sizeof(bool)* scale * scale);

int scale = 4;
bool * bBoard;
//int * board;
int board[400] =
{
	2,0,0,0,
	0,4,2,0,
	2,2,4,2,
	2,2,2,2
};



enum class MOVE
{
	LEFT, RIGHT, UP, DOWN
};

enum class TYPE
{
	SAME, DIFF, ZERO
};


void Move(MOVE eMov);
void Update(MOVE eMov, int index);
bool IsWallBlock(MOVE eMov, int index);
int findNextBlockIndex(MOVE eMov);
TYPE NextBlockTYPE(MOVE eMov, int index);
void MoveBlock(MOVE eMov, int index);

void Move(MOVE eMov)
{
	//검사하는 방향부터 검사해야함 모든 블럭 검사하기
	if (eMov == MOVE::RIGHT || eMov == MOVE::DOWN)
	{
		for (int i = (scale*scale)-1; -1 < i; --i)
		{
			Update(eMov, i);
		}
	}
	else 
	{
		for (int i = 0; i < scale* scale; ++i)
		{
			Update(eMov, i);
		}
	}
}

void Update(MOVE eMov, int index)
{
	if (IsWallBlock(eMov, index) == false)
	{
		MoveBlock(eMov, index);
	}
}

//벽에 붙어있는 블록인가? true면 벽에 붙어있는 블록
bool IsWallBlock(MOVE eMov, int index)
{
	switch (eMov)
	{
	case MOVE::LEFT:
		//맨 왼쪽 줄이 아니거나 && 왼쪽블럭의 숫자가 같다면
		if (index % scale != 0)
		return false;
		return true;
	case MOVE::RIGHT:
		if (index % scale == scale - 1)
		return true;
		return false;
	case MOVE::UP:
		if (index < scale)
		return true;
		return false;
	case MOVE::DOWN:
		if (scale * (scale -1) <= index)
		return true;
		return false;
	default : return true;
	}
}

//옆의 블록 추가 인덱스 계산
int findNextBlockIndex(MOVE eMov)
{
	switch (eMov)
	{
	case MOVE::LEFT:
		return -1;
	case MOVE::RIGHT:
		return 1;
	case MOVE::UP:
		return -scale;
	case MOVE::DOWN:
		return scale;
	}
	return 0;
}

//옆에 블록이 나와 무슨 관계인가
TYPE NextBlockTYPE(MOVE eMov, int index)
{
	int nextBlockDiff = index + findNextBlockIndex(eMov);

	if (board[index] == board[nextBlockDiff])
		return TYPE::SAME;
	if (board[nextBlockDiff] == 0)
		return TYPE::ZERO;

	return TYPE::DIFF;
}

//이동시에 모든상황
void MoveBlock(MOVE eMov, int index)
{
	TYPE eType;
	int nextBlockIndex = index;
	int diff = findNextBlockIndex(eMov);

	//DIFF, 벽블록 일때까지 해야겠네ㅋㅋㅋㅅㅂ
	do{
		eType = NextBlockTYPE(eMov, nextBlockIndex);
		nextBlockIndex += diff;

		if (eType == TYPE::SAME)
		{
			//합쳐졌었다는 의미로 -1를 두자!
			board[nextBlockIndex] = board[nextBlockIndex] * 2;
			board[nextBlockIndex-diff] = 0;
		}
		if (eType == TYPE::ZERO)
		{
			board[nextBlockIndex] = board[nextBlockIndex - diff];
			board[nextBlockIndex - diff] = 0;
		}

		if (IsWallBlock(eMov, nextBlockIndex) == true) break;
	} while (eType == TYPE::ZERO);
}

int findMaxInt()
{
	int result = 0;
	for (int i = 0; i < (scale * scale) - 1; ++i)
	{
		if(result < board[i])
			result = board[i];
	}
	return result;
}

int main()
{
	/*scanf("%d", &scale);
	for (int i = 0; i < scale * scale; ++i)
	{
		scanf("%d", board + i);
	}*/

	//board = new int[scale * scale];
	bBoard = new bool[scale * scale];
	CHECK_INIT

	for (int i = 0; i < scale; ++i) {

		for (int i = 0; i < scale*scale; ++i)
		{
			printf(" %d", board[i]);
			if (i % scale == scale-1 )
				printf("\n");
		}
		printf("\n\n");

		if(i%scale == 0)
			Move(MOVE::UP);
		if (i%scale == 1)
			Move(MOVE::DOWN);
		if (i%scale == 2)
			Move(MOVE::RIGHT);
		if (i%scale == 3)
			Move(MOVE::LEFT);
	}
}

//2048만들어서 5번 움직일건데 이때 얻을수있는 가장 큰 블록의 숫자 반환
//
//입력값: 
//1. 보드의 크기 N
//
//2. 각 숫자

//일단 체크부터하자
//TOOD::블록 체크하고 젤 큰 값 찾으면 될듯