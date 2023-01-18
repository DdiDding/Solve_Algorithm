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
//오리지널 맵
short m[8][8];
//cctv의각 맵이 저장될 배열
//[cctv의 저장된 순서][회전순서][맵의Y][맵의X]
short pre[8][4][8][8];

//cctv의 종류는 one index로 +1인 6으로 선언
short rotNum[6] = { 0, 4,2,4,4,1 };
//순서는 밑, 우, 상, 좌
bool rot[6][4] = {
	{9, 9, 9, 9},
	{1, 0, 0, 0},
	{1, 0, 1, 0},
	{1, 1, 0, 0},
	{1, 1, 1, 0},
	{1, 1, 1, 1},
};

//cctv의 개수
short cctv_n = 0;
//cctv의 종류저장 ,0이면 존재하지 않음
short cctv_c[8];
//cctv의 위치저장
pair<short,short> cctv_p[8];

//num = cctv의 종류
void RotCCTV(const short & num)
{
	short temp = rot[num][3];
	rot[num][3] = rot[num][2];
	rot[num][2] = rot[num][1];
	rot[num][1] = rot[num][0];
	rot[num][0] = temp;
}

//num = cctv의 저장된 순서
void SaveMap(const short & num)
{
	short c = cctv_c[num];

	short tY;
	short tX;
	//저장된 종류마다
	for (int i = 0; i < rotNum[c]; ++i)
	{
		//밑방향 체크
		if (rot[c][0] == true)
		{
			tX = cctv_p[num].X;
			tY = cctv_p[num].Y;
			
			for (; tY < y; ++tY)
			{
				//벽이면 종료
				if (m[tY][tX] == 6)
				{
					//저장맵에 벽 추가하고 종료
					pre[num][c][tY][tX] = 1;
					break;
				}
				pre[num][i][tY][tX] = 1;
			}
		}
		//우방향 체크
		if (rot[c][1] == true)
		{
			tX = cctv_p[num].X;
			tY = cctv_p[num].Y;

			for (; tX < x; ++tX)
			{
				//벽이면 종료
				if (m[tY][tX] == 6)
				{
					//저장맵에 벽 추가하고 종료
					pre[num][c][tY][tX] = 1;
					break;
				}
				pre[num][i][tY][tX] = 1;
			}
		}
		//상방향 체크
		if (rot[c][2] == true)
		{
			tX = cctv_p[num].X;
			tY = cctv_p[num].Y;

			for (; 0 <= tY; --tY)
			{
				//벽이면 종료
				if (m[tY][tX] == 6)
				{
					//저장맵에 벽 추가하고 종료
					pre[num][c][tY][tX] = 1;
					break;
				}
				pre[num][i][tY][tX] = 1;
			}
		}
		//좌방향 체크
		if (rot[c][3] == true)
		{
			tX = cctv_p[num].X;
			tY = cctv_p[num].Y;

			for (; 0 <= tX; --tX)
			{
				//벽이면 종료
				if (m[tY][tX] == 6)
				{
					//저장맵에 벽 추가하고 종료
					pre[num][c][tY][tX] = 1;
					break;
				}
				pre[num][i][tY][tX] = 1;
			}
		}
		
		//회전방향 바꿔주고
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
			//cctv일때
			if (1 <= m[i][j] && m[i][j] < 6)
			{
				cctv_c[cctv_n] = m[i][j];
				cctv_p[cctv_n] = { i,j };
				++cctv_n;
			}
		}
	}

	//cctv마다 모든 회전의 맵 저장하기
	for (int i = 0; i < cctv_n; ++i)
	{
		SaveMap(i);
	}

	//각 cctv의 모든 회전끼리 합쳐서 사각지대 개수 구하기


	//그 개수중 최소크기 반환

	return 0;
}