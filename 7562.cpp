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
	//�̹� ������ ��
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

			//�������� ��ġ���� Ȯ��
			if (nY < 0 || L <= nY || nX < 0 || L <= nX) continue;

			//�湮�Ǿ��ִ��� Ȯ��
			if (1 <= arr[nY][nX]) continue;

			//�����ϸ�
			if (nY == E.Y && nX == E.X) return arr[cY][cX] + 1;

			//������ �ƴϸ� ť�� ���� �� �湮ó��
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