#include <bits/stdc++.h>
using namespace std;

/*
게임 판 : 9 * 9
채울수 있는건 채우고 
모르는건 이제 재귀로 ?
*/

int m[9][9];

typedef pair<int, int> pii;
vector<pii> zero;
#define X first
#define Y second

int BT(int n)
{

	//채울수 있는건 채워,
	vector<int>a;
	
	return 0;
}

int main()
{
	ios::sync_with_stdio(0), cin.tie(0);
	for (int i = 0; i < 9; ++i)
	{
		for (int j = 0; j < 9; ++j)
		{
			cin >> m[i][j];
			if (m[i][j] == 0) zero.push_back({ j,i });
		}
	}



	return 0;
}