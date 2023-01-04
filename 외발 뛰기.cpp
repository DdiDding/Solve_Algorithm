#include <iostream>
#include <string.h>
using namespace std;
int n;
//one based array
int board[101][101];

bool solve(int y, int x)
{
	//기저사례 1. 판을 넘어갈 경우
	if (n < y || n < x) return false;
	//기저사례 2. 도착할 경우
	if (n == x && n == y) return true;

	//오른쪽 아니면 밑으로 이동한 결과중 true가 있으면 받는다.
	return solve(y, x + board[y][x]) || solve(y + board[y][x], x);
}

int main()
{
	int t; cin >> t;
	while (t--)
	{
		cin >> n;
		memset(board, -1, sizeof(int) * n);
		for (int i = 1; i <= n; ++i)
		{
			for (int j = 1; j <= n; ++j)
			{
				cin >> board[i][j];
			}
		}

		cout << (solve(1, 1) ? "YES\n" : "NO\n");
	}
	return 0;
}

/*
n * n크기에
좌측상단부터 판에 써진 수만큼 오른쪽 혹은 밑으로 갈수 있다.
우측하단에 도착할 방법이 있는가?

완탐시 2^100
*/