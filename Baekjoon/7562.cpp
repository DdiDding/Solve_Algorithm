#include <iostream>
#include <queue>
#include <cstring>

#define MAX 301
#define Y first
#define X second
using namespace std;

pair<int, int> pre[8] = {{2,1},{1,2},{-1,2},{-2,1},{-2,-1},{-1,-2 },{1,-2},{2,-1}};
int arr[MAX][MAX];

int BFS(const int & L,const pair<int, int> & S, const pair<int, int> & E)
{
	//이미 도착일 때
	if (S.X == E.X && S.Y == E.Y) return 0;

	queue<pair<int, int>> q;
	int cX, cY, nX, nY;
	q.push({ S.Y, S.X });

	while (q.empty() == false)
	{
		cY = q.front().Y;
		cX = q.front().X;
		q.pop();

		for (int i = 0; i < 8; ++i)
		{
			nY = cY + pre[i].Y;
			nX = cX + pre[i].X;

			//정상적인 위치인지 확인
			if (nY < 0 || L <= nY || nX < 0 || L <= nX) continue;

			//방문되어있는지 확인
			if (1 <= arr[nY][nX]) continue;

			//도착하면
			if (nY == E.Y && nX == E.X) return arr[cY][cX] + 1;

			//도착이 아니면 큐에 삽입 후 방문처리
			q.push({ nY,nX });
			arr[nY][nX] = arr[cY][cX] + 1;
		}
	}
	return -1;
}

int main()
{
	ios::sync_with_stdio(0), cin.tie(0);
	int T, L; cin >> T;
	pair<int,int> S, E;
	while (T--)
	{
		//set initial value
		memset(arr, 0, sizeof(arr));
		cin >> L;
		cin >> S.Y >> S.X;
		cin >> E.Y >> E.X;

		//Do BFS
		cout << BFS(L, S, E) << "\n";
	}
	return 0;
}