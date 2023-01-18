#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

#define MAX_MAP 51
#define PUSH(y,x) push(make_pair(y,x))
#define GETY first
#define GETX second

int preX[4] = { 0, 1, 0, -1 };
int preY[4] = { 1, 0, -1, 0 };

int map[MAX_MAP][MAX_MAP];
queue<pair<int,int>> q;
void BFS(const int & Y, const int & X, const int & column,const int & row)
{
	//1. set start node
	q.push(make_pair(Y, X));
	
	//2. loop
	while (q.empty() == false)
	{
		//큐에서 방문 처리
		pair<int, int> temp = q.front(); q.pop();

		if (map[temp.GETY][temp.GETX] == 0) continue;
		map[temp.GETY][temp.GETX] = 0;

		//인접노드 확인
		for (int i = 0; i < 4; ++i)
		{
			int nextX = temp.GETX + preX[i];
			int nextY = temp.GETY + preY[i];
			if (0 <= nextX && nextX < row && 0 <= nextY && nextY < column)
				if (map[nextY][nextX] == 1)
					q.push(make_pair(nextY, nextX));
		}
	}
	return;
}

int main()
{
	ios::sync_with_stdio(0), cin.tie(0);
	int T, M, N, K, X, Y; cin >> T;
	int result;
	while (T--)
	{
		//1. init & get input
		cin >> M >> N >> K;
		result = 0;
		memset(map, 0, sizeof(map));

		while (K--)
		{
			cin >> X >> Y;
			map[Y][X] = 1;
		}

		//2. BFS
		for (int y = 0; y < N; ++y)
		{
			for (int x = 0; x < M; ++x)
			{
				if (map[y][x] == 1)
				{
					BFS(y, x, N, M);
					++result;
				}
			}
		}

		//3. Print
		cout << result << "\n";
	}
	return 0;
}