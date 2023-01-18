#include <bits/stdc++.h>
using namespace std;

char board[51][51];
int n, tmp;


void garo() {
	for (int i = 0; i < n; i++)
	{
		int cnt = 1;
		for (int j = 0; j < n; j++)
		{
			if (board[i][j] == board[i][j + 1])
				cnt++;
			else
				tmp = max(tmp, cnt);
		}

	}
}



void sero() {
	for (int i = 0; i < n; i++)
	{
		int cnt = 1;
		for (int j = 0; j < n; j++)
		{
			if (board[j][i] == board[j + 1][i])
				cnt++;
			else
				tmp = max(tmp, cnt);
		}

	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> n;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < 5; j++)
			cin >> board[i][j];

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n - 1; j++)
		{
			swap(board[i][j], board[i][j + 1]);

			garo();
			sero();

			swap(board[i][j], board[i][j + 1]);
		}
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n - 1; j++)
		{
			swap(board[j][i], board[j + 1][i]);

			garo();
			sero();

			swap(board[j][i], board[j + 1][i]);
		}
	}

	cout << tmp;

	return 0;
}