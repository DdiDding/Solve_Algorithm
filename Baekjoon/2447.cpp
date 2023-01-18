#include <bits/stdc++.h>
using namespace std;
const int MAX = 2190;
char m[MAX][MAX];

void SetStar(int y, int x)
{
	for (int i = 0; i < 3; ++i)
	{
		for (int j = 0; j < 3; ++j)
		{
			if (i == 1 && j == 1) continue;
			m[y + i][x + j] = '*';
		}
	}
}

void solve(int y, int x, int len)
{
	//�������
	if (len == 3)
	{
		SetStar(y, x);
		return;
	}

	//9��� �Ѵ�.
	int l = len / 3;
	for (int i = 0; i < 3; ++i)
	{
		for (int j = 0; j < 3; ++j)
		{
			if (i == 1 && j == 1) continue;
			solve(y + (l * i), x + (l * j), l);
		}
	}
	return;
}

int main()
{
	//1. Get input value
	ios::sync_with_stdio(0), cin.tie(0);
	int n; cin >> n;
	fill_n(&m[0][0], MAX * MAX, ' ');

	//2. Do recursive
	solve(0, 0, n);

	//3. Print
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			cout << m[i][j];
		}
		cout << '\n';
	}
	return 0;
}

/*
2�����迭�� 0,1�� �Ǵ�
0�̸� ��ĭ, 1�̸� ��ǥ

m[n][n];

//m[y][x]���� len���̸�ŭ �������� �κп� ���� ����Ѵ�.
solve(int y, int x, int len)
{
	//�������
	1.len�� 3�϶� �ϵ��ڵ����� �ֱ�

	2.�ƴ϶�� 9����ϱ�
		2-1. 5��°�� ��� ��ĭ �����(�׳� ó���� 0���� ���ΰ� �н��ϸ� �ɵ�)

	����
}

*/