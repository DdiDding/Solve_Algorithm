#include <iostream>
#include <stdio.h>
#include <string>
#include <algorithm>
#include <functional>
#include <vector>
#include <map>
#include <cstring>
#include <stack>
#include <queue>

#define MAX 1001
#define WALL first
#define X second.first
#define Y second.second
using namespace std;

int arr[2][MAX][MAX];
pair<bool, pair<int, int>> pre[4] = { {1,{0,1}},{1,{1,0}},{1,{0,-1}},{1,{-1,0}} };

void BFS(const int & maxX, const int & maxY)
{
	queue<pair<bool, pair<int, int>>> q;
	bool broken = (arr[0][1][1] == 1) ? true : false;
	q.push({ broken,{1,1} });
	arr[0][1][1] = 1;


	//1,1이 벽인 경우 예외처리하기
	int cX, cY, nX, nY;
	while (q.empty() == false)
	{
		cX = q.front().X;
		cY = q.front().Y;
		broken = q.front().WALL;
		q.pop();

		for (int i = 0; i < 4; ++i)
		{
			nX = cX + pre[i].X;
			nY = cY + pre[i].Y;

			//유효한 영역인지 확인
			if (nX < 1 || maxX < nX || nY < 1 || maxY < nY) continue;

			//기준 타일이 아직 벽을 부수지 않았으면
			if (broken == false)
			{
				//이동할 타일이 벽이면
				if (arr[0][nY][nX] == 1)
				{
					//벽이 부숴젔었는지 확인
					if (1 <= arr[1][nY][nX]) continue;

					//안 부숴졌었으면 큐 삽입후 , [1]번에 방문처리
					q.push({ true,{nX,nY} });
					if (arr[1][cY][cX] == 0) arr[1][cY][cX] = arr[0][cY][cX];
					arr[1][nY][nX] = arr[0][cY][cX] + 1;
				}
				//이동할 타일이 아무도 방문하지 않았다면
				else if (arr[0][nY][nX] == 0)
				{
					//큐 삽입후 , 방문처리
					q.push({ false,{nX,nY} });
					arr[0][nY][nX] = arr[0][cY][cX] + 1;
				}
			}
			//기준 타일이 벽을 부수었고
			else
			{
				//이동할 타일이 벽이면 패스
				if (arr[0][nY][nX] == 1) continue;
				//이동할 타일이 누구도 방문하지 않았다면
				if (arr[1][nY][nX] == 0)
				{
					//큐 삽입후 , 방문처리
					q.push({ true,{nX,nY} });
					arr[1][nY][nX] = arr[1][cY][cX] + 1;
				}
			}
		}
	}
	return;
}

int main()
{
	int y, x; cin >> y >> x;

	for (int i = 1; i <= y; ++i)
	{
		for (int j = 1; j <= x; ++j)
		{
			scanf("%1d", &arr[0][i][j]);
		}
	}

	BFS(x, y);

	int result_0 = arr[0][y][x];
	int result_1 = arr[1][y][x];

	if (result_0 + result_1 == 0) cout << -1;
	else if (result_0 == 0)	cout << result_1;
	else if (result_1 == 0) cout << result_0;
	else cout << min(result_0, result_1);

	return 0;
}