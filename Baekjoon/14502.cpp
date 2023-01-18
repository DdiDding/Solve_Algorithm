#include <bits/stdc++.h>
using namespace std;

const int dx[4] = { 0, 0, 1, 1 };
const int dy[4] = { 0, 1, 0, 1 };

int board[9][9];

int main()
{
	ios::sync_with_stdio(0), cin.tie(0);

	int n, m;
	cin >> n >> m;

	//보드 입력
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			cin >> board[i][j];
		}
	}



	return 0;
}

/*
바이러스 확산을 막기 위해 연구소에 벽을 세운다.

연구소의 크기 N x M
0 - 빈 칸
1 - 벽
2 - 감염 칸

바이러스는 상하좌우로 퍼져나간다.
새로 세울 수 있는 벽의 개수는 3개, 꼭 3개 세운다.

*/