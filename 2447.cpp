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
	//기저사례
	if (len == 3)
	{
		SetStar(y, x);
		return;
	}

	//9등분 한다.
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
2차원배열의 0,1로 판단
0이면 빈칸, 1이면 별표

m[n][n];

//m[y][x]부터 len길이만큼 나누어진 부분에 별을 기록한다.
solve(int y, int x, int len)
{
	//기저사례
	1.len이 3일때 하드코딩으로 넣기

	2.아니라면 9등분하기
		2-1. 5번째는 모두 빈칸 만들기(그냥 처음에 0으로 놔두고 패스하면 될듯)

	리턴
}

*/