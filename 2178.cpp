#include <iostream>
#include <stdio.h>
#include <queue>
#define MAX 101
#define X second
#define Y first

using namespace std;

int maze[MAX][MAX] = {0,};

int pX[4] = { 0,1,0,-1 };
int pY[4] = { 1,0,-1,0 };

pair<int, int> s;
pair<int, int> e;

queue<pair<int, int>> q;
void BFS( )
{
	q.push(make_pair(1,1));

	while (q.empty() == false)
	{
		for (int i = 0; i < 4; ++i)
		{
			int ny = q.front().Y + pY[i];
			int nx = q.front().X + pX[i];

			//도착하지 않았으면 인접노드 큐에 삽입 후 방문 처리
			if (1 <= ny && ny <= e.Y && 1 <= nx && nx <= e.X)
			{
				if (maze[ny][nx] == 1)
				{
					q.push(make_pair(ny, nx));
					maze[ny][nx] = maze[q.front().Y][q.front().X] + 1;
				}
			}
			//도착했는지 확인
			if (ny == e.Y && nx == e.X) return;
		}
		q.pop();
	}
}

int main()
{
	//1. Get input value
	s = make_pair(1, 1);
	cin >> e.Y>> e.X;
	
	for (int i = 1; i <= e.Y; ++i)
	{
		for (int j = 1; j <= e.X; ++j)
		{
			scanf("%1d", &maze[i][j]);
		}
	}

	//2. BFS
	BFS();

	//3. Print
	cout << maze[e.Y][e.X];
	return 0;
}