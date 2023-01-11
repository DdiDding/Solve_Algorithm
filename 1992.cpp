#include <bits/stdc++.h>
using namespace std;

int n;
char s[66][66];

string solve(int y, int x, int len)
{
	string ret = "";

	//���� �Ǿ����� �˻�
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
����, ����Ʈ��
��  �� = 0
������ = 1

(0   (0011)  (0(0111)01)  1) 

//������� ��ǥ�� map[y][x]�̸� ���� ���̰� len�� ���� �˻�
string solve(int y, int x, int len)
{
	string ret = '('

	1. ���� �Ǿ����� �˻�.
	1-1. True : return ���ϵ� �� + ')'
	
	2. for( 4��� �Ѵ�. )[�ݺ�]
	{
		2-1. ret += solve(�� ��е� ��ǥ�� ����)
	}

	return ret + )
}

*/