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

	//���� �Է�
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
���̷��� Ȯ���� ���� ���� �����ҿ� ���� �����.

�������� ũ�� N x M
0 - �� ĭ
1 - ��
2 - ���� ĭ

���̷����� �����¿�� ����������.
���� ���� �� �ִ� ���� ������ 3��, �� 3�� �����.

*/