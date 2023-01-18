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
	//�˻��ϴ� ������� �˻��ؾ��� ��� �� �˻��ϱ�
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

//���� �پ��ִ� ����ΰ�? true�� ���� �پ��ִ� ���
bool IsWallBlock(MOVE eMov, int index)
{
	switch (eMov)
	{
	case MOVE::LEFT:
		//�� ���� ���� �ƴϰų� && ���ʺ��� ���ڰ� ���ٸ�
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

//���� ��� �߰� �ε��� ���
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

//���� ����� ���� ���� �����ΰ�
TYPE NextBlockTYPE(MOVE eMov, int index)
{
	int nextBlockDiff = index + findNextBlockIndex(eMov);

	if (board[index] == board[nextBlockDiff])
		return TYPE::SAME;
	if (board[nextBlockDiff] == 0)
		return TYPE::ZERO;

	return TYPE::DIFF;
}

//�̵��ÿ� ����Ȳ
void MoveBlock(MOVE eMov, int index)
{
	TYPE eType;
	int nextBlockIndex = index;
	int diff = findNextBlockIndex(eMov);

	//DIFF, ����� �϶����� �ؾ߰ڳפ���������
	do{
		eType = NextBlockTYPE(eMov, nextBlockIndex);
		nextBlockIndex += diff;

		if (eType == TYPE::SAME)
		{
			//���������ٴ� �ǹ̷� -1�� ����!
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

//2048���� 5�� �����ϰǵ� �̶� �������ִ� ���� ū ����� ���� ��ȯ
//
//�Է°�: 
//1. ������ ũ�� N
//
//2. �� ����

//�ϴ� üũ��������
//TOOD::��� üũ�ϰ� �� ū �� ã���� �ɵ�