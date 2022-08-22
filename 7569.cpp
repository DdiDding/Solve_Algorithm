#include <iostream>
#include <queue>

#define MAX 101
#define X first
#define Y second.first
#define Z second.second

using namespace std;

int arr[MAX][MAX][MAX] = { 0, };
pair<int, pair<int, int>> pre[6] = { {0,{1,0}}, {1,{0,0}}, {0,{-1,0}}, {-1,{0,0}}, {0,{0,1}}, {0,{0,-1}} };

queue<pair<int, pair<int, int>>> q;
int BFS(int & zeroNum, const int & maxX, const int & maxY, const int & maxZ)
{
	//익지 않은 토마토가 없을 때
	if (zeroNum == 0) return 0;

	int day = 0;
	int x, nX, y, nY, z, nZ;
	while (q.empty() == false)
	{
		++day;
		int q_size = q.size();
		for (int i = 0; i < q_size; ++i)
		{
			x = q.front().X; y = q.front().Y; z = q.front().Z;
			q.pop();
			for (int j = 0; j < 6; ++j)
			{
				nX = x + pre[j].X; nY = y + pre[j].Y; nZ = z + pre[j].Z;

				//범위 밖인지 검사
				if (nX < 0 || maxX <= nX || nY < 0 || maxY <= nY || nZ < 0 || maxZ <= nZ) continue;

				//안익은 토마토인지 검사
				if (arr[nZ][nY][nX] != 0) continue;

				//안익은 토마토로 간주하고 1로 변경하고 큐에 삽입 후 zeroCnt 감소
				arr[nZ][nY][nX] = 1;
				q.push({nX,{nY,nZ}});
				--zeroNum;
			}
		}

		//안익은 모든 토마토가 모두 익었는지
		if (zeroNum == 0) return day;
	}

	return -1;
}


int main()
{
	ios::sync_with_stdio(0), cin.tie(0);
	int n, m, h; cin >> n >> m >> h;

	int zeroNum = 0;
	for (int z = 0; z < h; ++z)
	{
		for (int y = 0; y < m; ++y)
		{
			for (int x = 0; x < n; ++x)
			{
				cin >> arr[z][y][x];
				if (arr[z][y][x] == 0) ++zeroNum;
				if (arr[z][y][x] == 1) q.push({x,{y,z}});
			}
		}
	}

	cout << BFS(zeroNum, n, m, h);

	return 0;
}