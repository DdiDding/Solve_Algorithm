#include <iostream>
#include <algorithm>
#include <string.h>
#define PF(x) Preset[x].first
#define PS(x) Preset[x].second

using namespace std;
typedef pair<int, int> pii;

int C, Y, X;

//False면 검은 블록(#), True면 하얀 블록(.)
bool map[21][21];
void PrintMap()
{
	for (int i = 0; i < Y; ++i)
	{
		for (int j = 0; j < X; ++j)
		{
			if (map[i][j] == false) cout << '#';
			else cout << '.';
		}
		cout << endl;
	}
	cout << endl;
}

pii Preset[4]{ {0,2},{1,2},{0,1},{2,3} };
int PX[4] = { 1, 1, 0, -1};
int PY[4] = { 0, 1, 1, 1};

bool CheckBlock(int i, int CX, int CY)
{
	int NX_1 = CX + PX[PF(i)];
	int NY_1 = CY + PY[PF(i)];
	int NX_2 = CX + PX[PS(i)];
	int NY_2 = CY + PY[PS(i)];
	//게임판 안에 있는지 확인
	if (0 <= NX_1 && NX_1 < X && NY_1 < Y &&
		0 <= NX_2 && NX_2 < X && NY_2 < Y)
	{
		if (map[NY_1][NX_1] == true && map[NY_2][NX_2] == true) return true;
	}
	return false;
}

int Counting( )
{
	int CX = -1, CY = -1;
	//가장 우측상단에 있는 흰칸 찾기
	for (int i = 0; i < Y; ++i)
	{
		for (int j = 0; j < X; ++j)
		{
			if (map[i][j] == true)
			{
				CY = i;
				CX = j;
				break;
			}
		}
		if (0 < CX) break;
	}
	if (CX == -1)
	{
		return 1;
	}
	int ret = 0;

	//4가지 경우의 수를 확인해본다.
	for (int i = 0; i < 4; ++i)
	{
		if (CheckBlock(i, CX, CY) == true)
		{
			map[CY][CX] = false;
			map[CY + PY[PF(i)]] [CX + PX[PF(i)]] = false;
			map[CY + PY[PS(i)]] [CX + PX[PS(i)]] = false;

			//다음 흰칸 찾기
			ret += Counting();

			map[CY][CX] = true;
			map[CY + PY[PF(i)]][CX + PX[PF(i)]] = true;
			map[CY + PY[PS(i)]][CX + PX[PS(i)]] = true;
		}
	}
	return ret;
}

int main()
{
	cin >> C;
	while (C--)
	{
		//1. init & intput value
		memset(map, 0, sizeof(map));
		cin >> Y >> X;

		char temp;
		int ret = 0;
		int white = 0;
		for (int i = 0; i < Y; ++i)
		{
			for (int j = 0; j < X; ++j)
			{
				cin >> temp;
				if (temp == '.')
				{
					map[i][j] = true;
					++white;
				}
			}
		}

		if (white % 3 == 0)
		{
			ret = Counting();
		}

		cout << ret;
	}
}



/*
H * W 크기의 게임판
3칸짜리 L자 블록으로 흰부분을 채우는 모든 경우의 수 구하기

1.모든칸을 좌측 상단부터 오른쪽으로 차례대로 검사할것.

2.하얀칸이라면 L자 블록을 놓는 시도를 한다. (8가지의 경우의 수)
2-1.놓게 되면 재귀로 들어가 다음 칸을 조사한다.
2-2.놓을수 없으면 return
2-3.모두 놓게 되면 result에 카운트

--------------
8가지의 경우의 수를 어떻게?
24번계산하지 말고
계산은 8칸만 딱 하고, 맞는걸 선택하는게 좋을거같은데
*/