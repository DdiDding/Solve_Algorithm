#include <iostream>
#include <algorithm>
#include <string.h>
#define PF(x) Preset[x].first
#define PS(x) Preset[x].second

using namespace std;
typedef pair<int, int> pii;

int C, Y, X;

//False�� ���� ���(#), True�� �Ͼ� ���(.)
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
	//������ �ȿ� �ִ��� Ȯ��
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
	//���� ������ܿ� �ִ� ��ĭ ã��
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

	//4���� ����� ���� Ȯ���غ���.
	for (int i = 0; i < 4; ++i)
	{
		if (CheckBlock(i, CX, CY) == true)
		{
			map[CY][CX] = false;
			map[CY + PY[PF(i)]] [CX + PX[PF(i)]] = false;
			map[CY + PY[PS(i)]] [CX + PX[PS(i)]] = false;

			//���� ��ĭ ã��
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
H * W ũ���� ������
3ĭ¥�� L�� ������� ��κ��� ä��� ��� ����� �� ���ϱ�

1.���ĭ�� ���� ��ܺ��� ���������� ���ʴ�� �˻��Ұ�.

2.�Ͼ�ĭ�̶�� L�� ����� ���� �õ��� �Ѵ�. (8������ ����� ��)
2-1.���� �Ǹ� ��ͷ� �� ���� ĭ�� �����Ѵ�.
2-2.������ ������ return
2-3.��� ���� �Ǹ� result�� ī��Ʈ

--------------
8������ ����� ���� ���?
24��������� ����
����� 8ĭ�� �� �ϰ�, �´°� �����ϴ°� �����Ű�����
*/