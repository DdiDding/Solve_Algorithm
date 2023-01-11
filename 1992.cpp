#include <bits/stdc++.h>
using namespace std;

int n;
char s[66][66];

string solve(int y, int x, int len)
{
	string ret = "";

	//통일 되었는지 검사
	char std = s[y][x];
	bool isSame = true;
	for (int i = y; i < y + len && isSame; ++i)
	{
		for (int j = x; j < x + len && isSame; ++j)
		{
			if (std != s[i][j]) isSame = false;
		}
	}

	if (isSame == true) return ret += std;

	ret += '(';
	int l = len / 2;
	for (int i = 0; i < 2; ++i)
	{
		for (int j = 0; j < 2; ++j)
		{
			ret += solve(y + (l * i), x + (l * j), l);
		}
	}
	return ret += ')';
}

int main()
{
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			cin >> s[i][j];
		}
	}

	cout << solve(0, 0, n);

	return 0;
}

/*
압축, 쿼드트리
흰  점 = 0
검은점 = 1

(0   (0011)  (0(0111)01)  1) 

//좌측상단 좌표가 map[y][x]이며 변의 길이가 len인 영역 검사
string solve(int y, int x, int len)
{
	string ret = '('

	1. 통일 되었는지 검사.
	1-1. True : return 통일된 값 + ')'
	
	2. for( 4등분 한다. )[반복]
	{
		2-1. ret += solve(각 등분된 좌표와 길이)
	}

	return ret + )
}

*/