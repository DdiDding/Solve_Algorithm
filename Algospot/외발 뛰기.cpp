#include <iostream>
#include <string.h>
using namespace std;
int n;
//one based array
int board[101][101];
int cache[101][101];

int solve(int y, int x)
{
	//������� 1. ���� �Ѿ ���
	if (n < y || n < x) return 0;
	//������� 2. ������ ���
	if (n == x && n == y) return 1;

	//�޸����̼�
	int & ret = cache[y][x];
	if (ret != -1) return ret;

	//������ �ƴϸ� ������ �̵��� ����� true�� ������ �޴´�.
	return ret = solve(y, x + board[y][x]) || solve(y + board[y][x], x);
}

int main()
{
	int t; cin >> t;
	while (t--)
	{
		cin >> n;
		memset(cache, -1, sizeof(cache));
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
n * nũ�⿡
������ܺ��� �ǿ� ���� ����ŭ ������ Ȥ�� ������ ���� �ִ�.
�����ϴܿ� ������ ����� �ִ°�?

��Ž�� 2^100

#include <iostream>
#include <string.h>
using namespace std;
int n;
//one based array
int board[101][101];

bool solve(int y, int x)
{
	//������� 1. ���� �Ѿ ���
	if (n < y || n < x) return false;
	//������� 2. ������ ���
	if (n == x && n == y) return true;

	//������ �ƴϸ� ������ �̵��� ����� true�� ������ �޴´�.
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
*/