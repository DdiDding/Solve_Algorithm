#include <iostream>
#include <string>
#include <algorithm>
#include <functional>
#include <vector>
#include <map>
#include <set>
#include <cstring>
#include <stack>
#include <queue>
using namespace std;

#define Y first
#define X second

short y, x;
//�������� ��
short m[8][8];
//cctv�ǰ� ���� ����� �迭
//[cctv�� ����� ����][ȸ������][����Y][����X]
short pre[8][4][8][8];

//cctv�� ������ one index�� +1�� 6���� ����
short rotNum[6] = { 0, 4,2,4,4,1 };
//������ ��, ��, ��, ��
bool rot[6][4] = {
	{9, 9, 9, 9},
	{1, 0, 0, 0},
	{1, 0, 1, 0},
	{1, 1, 0, 0},
	{1, 1, 1, 0},
	{1, 1, 1, 1},
};

//cctv�� ����
short cctv_n = 0;
//cctv�� �������� ,0�̸� �������� ����
short cctv_c[8];
//cctv�� ��ġ����
pair<short,short> cctv_p[8];

//num = cctv�� ����
void RotCCTV(const short & num)
{
	short temp = rot[num][3];
	rot[num][3] = rot[num][2];
	rot[num][2] = rot[num][1];
	rot[num][1] = rot[num][0];
	rot[num][0] = temp;
}

//num = cctv�� ����� ����
void SaveMap(const short & num)
{
	short c = cctv_c[num];

	short tY;
	short tX;
	//����� ��������
	for (int i = 0; i < rotNum[c]; ++i)
	{
		//�ع��� üũ
		if (rot[c][0] == true)
		{
			tX = cctv_p[num].X;
			tY = cctv_p[num].Y;
			
			for (; tY < y; ++tY)
			{
				//���̸� ����
				if (m[tY][tX] == 6)
				{
					//����ʿ� �� �߰��ϰ� ����
					pre[num][c][tY][tX] = 1;
					break;
				}
				pre[num][i][tY][tX] = 1;
			}
		}
		//����� üũ
		if (rot[c][1] == true)
		{
			tX = cctv_p[num].X;
			tY = cctv_p[num].Y;

			for (; tX < x; ++tX)
			{
				//���̸� ����
				if (m[tY][tX] == 6)
				{
					//����ʿ� �� �߰��ϰ� ����
					pre[num][c][tY][tX] = 1;
					break;
				}
				pre[num][i][tY][tX] = 1;
			}
		}
		//����� üũ
		if (rot[c][2] == true)
		{
			tX = cctv_p[num].X;
			tY = cctv_p[num].Y;

			for (; 0 <= tY; --tY)
			{
				//���̸� ����
				if (m[tY][tX] == 6)
				{
					//����ʿ� �� �߰��ϰ� ����
					pre[num][c][tY][tX] = 1;
					break;
				}
				pre[num][i][tY][tX] = 1;
			}
		}
		//�¹��� üũ
		if (rot[c][3] == true)
		{
			tX = cctv_p[num].X;
			tY = cctv_p[num].Y;

			for (; 0 <= tX; --tX)
			{
				//���̸� ����
				if (m[tY][tX] == 6)
				{
					//����ʿ� �� �߰��ϰ� ����
					pre[num][c][tY][tX] = 1;
					break;
				}
				pre[num][i][tY][tX] = 1;
			}
		}
		
		//ȸ������ �ٲ��ְ�
		RotCCTV(c);
	}
	
}

int main()
{
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> y >> x;
	for(int i = 0; i < y; ++i)
	{
		for (int j = 0; j < x; ++j)
		{
			cin >> m[i][j];
			//cctv�϶�
			if (1 <= m[i][j] && m[i][j] < 6)
			{
				cctv_c[cctv_n] = m[i][j];
				cctv_p[cctv_n] = { i,j };
				++cctv_n;
			}
		}
	}

	//cctv���� ��� ȸ���� �� �����ϱ�
	for (int i = 0; i < cctv_n; ++i)
	{
		SaveMap(i);
	}

	//�� cctv�� ��� ȸ������ ���ļ� �簢���� ���� ���ϱ�


	//�� ������ �ּ�ũ�� ��ȯ

	return 0;
}